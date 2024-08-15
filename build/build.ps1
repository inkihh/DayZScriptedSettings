###############################################################
#															  #
# IMPORTANT!!!												  #
#															  #
# Only commit and push changes that work for everybody		  #
#															  #
# Changes that are only for you personally should be done in  #
# your own local environment.ps1							  #
#															  #
###############################################################

if(!$PSScriptRoot) {
	Write-Output ""
    Write-Output 'FATAL ERROR: $PSScriptRoot is empty. Please contact inkihh'
	Write-Output "on his development Discord https://discord.gg/P3uTEtHwk9."
	Write-Output ""
	exit
}

$file_exists = Test-Path -Path "$PSScriptRoot/include/build_functions.ps1"

if (!$file_exists) {
	Write-Output ""
    Write-Output "FATAL ERROR: Can't find ./include/build_functions.ps1"
	Write-Output ""
	exit
}

. "$PSScriptRoot/include/build_functions.ps1"

$file_exists = Test-Path -Path "$PSScriptRoot/environment.ps1"

if (!$file_exists) {
	Write-Output ""
    Write-Output "FATAL ERROR Can't find environemt.ps1"
	Write-Output ""
	Write-Output "There should be a file called environment.ps1.orig in the same folder as"
	Write-Output "this build script. Copy it to environment.ps1 and edit all values"
	Write-Output ""
	DoExit
}

. "$PSScriptRoot/environment.ps1"

$serverip = (
    Get-NetIPConfiguration |
    Where-Object {
        $_.IPv4DefaultGateway -ne $null -and
        $_.NetAdapter.Status -ne "Disconnected"
    }
).IPv4Address.IPAddress

$serverport="2302"
$modpath="P:\DayZScriptedSettings"

$password=$env_password
$playername=$env_playername
$modlist=$env_modlist
$localmodlist=$env_localmodlist
$dayzclientpath=$env_dayzclientpath
$dayzclientmods=$env_dayzclientmods
$dayzlocalmodspath=$env_dayzlocalmodspath
$dayzserverpath=$env_dayzserverpath
$buildpath=$env_buildpath
$keypath=$env_keypath
$clientprofile=$env_clientprofile
$serverprofile=$env_serverprofile
$serverconfig=$env_serverconfig
$pboproject=$env_pboproject
$makepbo=$env_makepbo
$sign=$env_sign
$serverside=$env_serverside

$dowipe=$env_dowipe
$dopack=$env_dopack
$packmethod=$env_packmethod
$dosign=$env_dosign
$dokillserver=$env_dokillserver
$dokillclient=$env_dokillclient
$dostartserver=$env_dostartserver
$dostartclient=$env_dostartclient
$isserverside=$env_isserverside

if($modpath -match '\\$')
{
	Write-Output ""
	Write-Output "`$modpath ($modpath) cannot end with a backslash."
	Write-Output ""
	DoExit
}

$modpath_parts = $modpath.Split('\');

if($modpath_parts.length -lt 2)
{
	Write-Output ""
	Write-Output "`$modpath ($modpath) has less than 2 path elements."
	Write-Output 'Remember to use backslashes: \'
	Write-Output ""
	DoExit	
}

if($modpath_parts.length -gt 3)
{
	Write-Output ""
	Write-Output "`$modpath ($modpath) has more than 3 path elements."
	Write-Output ""
	DoExit	
}

if($modpath_parts[0].ToLower() -ne 'p:')
{
	Write-Output ""
	Write-Output "`$modpath ($modpath) has to start with p:\"
	Write-Output ""
	DoExit	
}

$modname = $modpath_parts[($modpath_parts.length - 1)]

if($modpath_parts.length -eq 2)
{
	cmd /c mklink /j ("p:\" + $modname) ($PSScriptRoot + "\..\src") 2>$null
}
else
{
	New-Item -ItemType Directory -Path ("p:\" + $modpath_parts[1]) 1>$null 2>$null
	cmd /c mklink /j ("p:\" + $modpath_parts[1] + "\" + $modname) ($PSScriptRoot + "\..\src") 2>$null
}

#
# Build full modpath
#
$fullModpaths = @()
foreach ($item in $modlist)
{
    $fullModpaths += $dayzclientmods + "\" + $item
}
$fullmodlist = $fullModpaths -join ";"

#
# Build full local modpath
#
$fullLocalModpaths = @()
foreach ($item in $localmodlist)
{
    $fullLocalModpaths += $dayzlocalmodspath + "\" + $item
}
$fullmodlist += ";" + $fullLocalModpaths -join ";"

#
# Add the built mod to the modpath
#
if($isserverside)
{
	$serverside += ";" + $buildpath + "\@" + $modname
} else {
	$fullmodlist += ";" + $buildpath + "\@" + $modname
}

if($dokillserver)
{
	NewSection -name "STOPPING THE SERVER"
	TASKKILL /IM DayZServer_x64.exe /F /T 2>$null
}

if($dokillclient)
{
	NewSection -name "STOPPING THE GAME"
	TASKKILL /IM DayZ_x64.exe /F /T 2>$null
}

cmd /c timeout 1

if($dowipe)
{
	NewSection -name "DO WIPE?"
	$response = Read-Host "(y = yes, any other key = skip)"

	if ($response -eq 'y' -or $response -eq 'Y') {
		Write-Output "Wiping..."
		Remove-Item -Path "$dayzserverpath\mpmissions\dayzOffline.chernarusplus\storage_1" -Recurse -Force 2>$null 
		Remove-Item -Path "$dayzserverpath\mpmissions\dayzOffline.chernarusplus\expansion" -Recurse -Force 2>$null 
	} else {
		Write-Output "Skipping wipe"
	}
}

$unixEpoch = [datetime]::new(1970, 1, 1, 0, 0, 0, [datetimekind]::Utc)
$currentDate = Get-Date
$unixtime = [int][math]::Round(($currentDate.ToUniversalTime() - $unixEpoch).TotalSeconds)

$logspath="$dayzserverpath\logs\$unixtime"
NewSection -name "MOVING LOGS TO $logspath"

mkdir "$logspath" 1>$null 2>$null

Move-Item "$serverprofile\*.log" "$logspath" 2>$null
Move-Item "$serverprofile\*.rpt" "$logspath" 2>$null
Move-Item "$serverprofile\*.mdmp" "$logspath" 2>$null
Move-Item "$serverprofile\*.adm" "$logspath" 2>$null

NewSection -name "DELETING CLIENT LOGS"

Remove-Item -Path "$clientprofile\*.log" 2>$null
Remove-Item -Path "$clientprofile\*.rpt" 2>$null
Remove-Item -Path "$clientprofile\*.mdmp" 2>$null
Remove-Item -Path "$clientprofile\*.adm" 2>$null

if($dopack)
{
	NewSection -name "PACKING"

	NewSection -name "DELETING OLD BUILD"
	Remove-Item -Path "$buildpath\@$modname" -Recurse 2>$null

	NewSection -name "CREATING PROFILE FOLDERS"
	New-Item -ItemType Directory -Path "$PSScriptRoot\profile\client" 1>$null 2>$null
	New-Item -ItemType Directory -Path "$PSScriptRoot\profile\server" 1>$null 2>$null

	NewSection -name "CREATING BUILD FOLDERS"
	New-Item -ItemType Directory -Path "$buildpath\@$modname\Addons" 1>$null 2>$null
	New-Item -ItemType Directory -Path "$buildpath\@$modname\Info" 1>$null 2>$null
	New-Item -ItemType Directory -Path "$buildpath\@$modname\Keys" 1>$null 2>$null

	NewSection -name "COPYING KEY"
	Copy-Item -Path "$keypath.bikey" -Destination "$buildpath\@$modname\Keys\" 2>$null
	Copy-Item -Path "$keypath.bikey" -Destination "$dayzserverpath\Keys\" 2>$null

	switch ($packmethod) {
		"pboproject" { Start-Process -FilePath "$pboproject" -ArgumentList "-S", "-$", "+J", "-W", "+N", "-C", "-K", "-P", "$modpath", "-M=$buildpath\@$modname" -Wait -NoNewWindow	}
		"makepbo" { Start-Process -FilePath "$makepbo" -ArgumentList "-X=*-U*.git,*.vscode,*.delete", "$modpath", "$buildpath\@$modname\Addons\$modname.pbo" -Wait -NoNewWindow }
		default { Write-Error -Message "Unknown pack method $packmethod"; exit }
	}
}

$file_exists = Test-Path -Path "$buildpath\@$modname\Addons\$modname.pbo"

if (!$file_exists) {
	Write-Output ""
    Write-Output "FATAL ERROR: Can't find $buildpath\@$modname\Addons\$modname.pbo"
	Write-Output "Packing seems to have failed. Check P:\temp\$modname.bin.log"
	Write-Output "and P:\temp\$modname.packing.log"
	Write-Output ""
	exit
}

if($dosign)
{
	NewSection -name "SIGNING"
	Start-Process -FilePath "$sign" -ArgumentList "$keypath.biprivatekey", "$buildpath\@$modname\Addons\$modname.pbo" -Wait -NoNewWindow
}

if($dostartserver)
{
	NewSection -name "STARTING SERVER"
	Start-Process -FilePath "$dayzserverpath\DayZServer_x64.exe" -ArgumentList "`"-port=$serverport`"", "-dologs", "-netLog", "-adminlog", "`"-config=$serverconfig`"", "`"-mod=$fullmodlist`"", "`"-profiles=$serverprofile`"",  "-scriptDebug=true", "-scrAllowFileWrite", "-equalmodrequired", "`"-servermod=$serverside`"" 
}

if($dostartclient)
{
	NewSection -name "STARTING CLIENT"
	Start-Process -FilePath "$dayzclientpath\DayZ_BE.exe" -ArgumentList "-dologs", "-nosplash", "-nopause", "`"-name=$playername`"", "-nobenchmark", "-skipIntro", "`"-password=$password`"", "`"-profiles=$clientprofile`"", "`"-connect=$serverip`"", "`"-port=$serverport`"", "`"-mod=$fullmodlist`""
}

