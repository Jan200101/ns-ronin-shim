# Northstar-Ronin shim

For launching Ronin via Northstar

## How to compile
- Get your toolchain of choice (MinGW or MSVC)
- Compile Library

## How to use
- Install [Ronin](https://github.com/TF2SR/Ronin)
- download the latest `Northstar.dll` from the releases and put it into the `ronin` folder
- On Linux install vcrun2022 using winetricks/protontricks
- Launch Titanfall 2 using `-northstar -profile=ronin`
- If you need help ask @jan200101 on the Titanfall 2 Speedrunning Discord

## Why
Ronin and Northstar both modify Titanfall 2 but cannot be installed side by side
this shim makes it possible to install them side by side while also making it possible to use Ronin on Linux without funky workarounds.
