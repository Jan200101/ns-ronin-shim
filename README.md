# Northstar-Ronin shim

For launching Ronin via Northstar

## How to compile
- Get your toolchain of choice and cmake
- Compile the Library

## How to use
- Install [Northstar](https://northstar.tf/) (lol)
- Install [Ronin](https://github.com/TF2SR/Ronin)
- download the latest `Northstar.dll` from the releases and put it into the `ronin` folder
- [LINUX] install vcrun2022 using winetricks/protontricks
- Launch Titanfall 2 using `-northstar -profile=ronin`
- If you need help ask @jan200101 on the Titanfall 2 Speedrunning Discord

## Why
Ronin and Northstar both modify Titanfall 2 but cannot be installed side by side
this shim makes it possible to install them side by side while also making it possible to use Ronin on Linux without funky workarounds.

### Why do you need Northstar to launch Ronin on Linux?
You don't but I have already spend my time making Northstar work on Linux with GE-Proton even explicitly setting up stuff just for Northstar to function properly.
If Ronin ever wants to support Linux directly they can just copy the Northstar stuff or ask me.
