param([string]$File, [string]$Root, [switch]$Run)

# bin is always created in the same folder as the .cpp file
$dir = Split-Path $File
$bin = Join-Path $dir 'bin'
New-Item -ItemType Directory -Path $bin -Force | Out-Null

$name = [IO.Path]::GetFileNameWithoutExtension($File)
$out  = Join-Path $bin "$name.exe"

& "C:\msys64\ucrt64\bin\g++.exe" -fdiagnostics-color=always -g $File -o $out
if ($LASTEXITCODE -eq 0) {
    Write-Host "Success -> $out"
    if ($Run) { & $out }
}
exit $LASTEXITCODE