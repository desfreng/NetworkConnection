# NetworkConnection
Very Simple TCP Socket Implementation.

## Build
If you want to build for [ev3dev platform](http://www.ev3dev.org/), you have to configure the project with this :
```bash
mkdir -d build
cd build/
qmake "CONFIG+=arm" ..
```
This will use the `arm-linux-gnueabi-g++` compiler. So you need to install it before.

Otherwise, you just have to configure like this :
```bash
mkdir -d build
cd build/
qmake ..
```
## Support or Contact

Email Adress : desfrene.gabriel@gmail.com
