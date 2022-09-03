<h1 align="center">
	<br>
	<br>
	<img width="500" src="media/bigint-logo.svg" alt="Bigint">
	<br>
	<br>
	<br>
</h1>


# BigInt
<h5>Big Integer derived from GMP MP</h5>

## BigInt derived from GMP MP. And it doesn't require additional dependencies. Bigint is a simplified version. Convenient syntax, OOP makes the code easy to read.

## Usage

```c++

#include <iostream>
#include "bigint.hpp"

using namespace bigint; 

int main(){
	BigInt a, b, c;
	a = 1024;
	b = "1024"; 
	
	c = a + b;
	std::cout << "a + b = " << c << std::endl;
	
	...
	
	c = BigInt::pow(a, b);
	std::cout << "Expower a ^ b = " << c << std::endl;
	
	return 0;
}


```



