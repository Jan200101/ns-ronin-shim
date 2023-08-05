# Northstar-Ronin shim

For launching Ronin via Northstar

## How to compile
- Get your toolchain of choice (MinGW or MSVC)
- Compile Library

## How to use
- Extract `R2Ronin` folder into game directory
- Extract `Ronin.dll` into the `R2Ronin` folder
- Move custom `Northstar.dll` into the `R2Ronin` folder
- Launch Northstar using `-northstar -profile=R2Ronin`

## Why
Northstar can load DLLs directly from a profile, which is perfect for Ronin.
While rebranding Ronin they changed the symbol names, so this project is intended as a shim to simply load Ronin from Northstar.

