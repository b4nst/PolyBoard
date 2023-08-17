# PolyBoard

![PolyBoard](asset/polyboard_logo.png)

## Uploading to a Launchpad Pro

To upload PolyBoard to your Launchpad Pro, you'll need a sysex tool for your host platform.
I recommend [Sysex Librarian](https://www.snoize.com/sysexlibrarian/) on macOS, and [MIDI OX](http://www.midiox.com/) on Windows.
On Linux, you can use [amidi](https://linux.die.net/man/1/amidi)

I won't describe how to use these tools, I'm sure you already know - and if you don't, their documentation is superior to mine! Here's what you need to do:

1. Download the [latest version](https://github.com/b4nst/PolyBoard/releases/latest) of PolyBoard.
1. Unplug your Launchpad Pro
1. Hold the "Setup" button down while connecting it to your host via USB (ensure it's connected to the host, and not to a virtual machine!)
1. The unit will start up in "bootloader" mode
1. Send the `polyboard.syx` file to the device MIDI port - it will briefly scroll "upgrading..." across the grid.
1. Wait for the update to complete, and for the device to reboot!

> Tip - set the delay between sysex messages to as low a value as possible, so you're not waiting about for ages while the firmware uploads!
