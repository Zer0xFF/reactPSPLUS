# reactPSPLUS

A simple code that will reset PS4 internal clock back to 2013 thus in turn activating PS+ Games that has been previously or are currently on the console

## Build

The code has been currently tested to build using [xvortex/ps4-payload-sdk](https://github.com/xvortex/ps4-payload-sdk)
however, i see no reason it wouldnt build with cturt or idc's sdk.
To add, the code is rather simple it can be easily ported to any other current SDK or even future SDK(s)

## Requirement

* PS4 must (at the moment) be on 5.05 update.
* have a payload loader running (aka http://crack.bargains/505k/ open twice until you see `Awaiting Payload...`)
  * or any other means of running this code on PS4

## Usage
send the payload to the PS4 using socat (note `192.168.1.1` should be changed to PS4 IP address)
```
socat FILE:reactPSPLUS.bin TCP:192.168.1.1:9020
```

## Notes
the payload would set the internal clock to 2013 and your PS+ games would start working,
you wouldn't even need to have HEN enabled to use these games since they're legit games and would work normally like any digital game,
if you're not connected to the internet, you will not need to run this exploit again.
it might be worthwhile dumping your games to make sure you never lose access to them.
