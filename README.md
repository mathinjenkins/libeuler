# libeuler

`libeuler` calculates an approximation of the base ![](http://www.sciweavers.org/tex2img.php?eq=e&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0) of the [natural logarithm](https://en.wikipedia.org/wiki/Natural_logarithm).

### Method
The approximation is done using the equation ![](http://www.sciweavers.org/tex2img.php?eq=%20%281%20%2B%20%20%5Cfrac%7B1%7D%7Bn%7D%20%29%5E%7Bn%7D%20&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0) where the value of `e` get more accurate as `n` gets bigger and bigger.

### Dependencies
* [libexponent](https://github.com/mathinjenkins/libexponent)
### Build
* `git clone git@github.com:mathinjenkins/libeuler.git`
* `cd libeuler`
* `mkdir build && cd build`
* `cmake ../`
* `make`
* `./test/euler_test`

### License
[MIT License](https://github.com/mathinjenkins/libexponent/blob/master/LICENSE)
