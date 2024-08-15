function NewSection
{
    param (
        [string]$name
    )
	Write-Output ""
	Write-Output "----------------------"
    Write-Output "$name"
}

function DoExit
{
	exit
}