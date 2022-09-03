<h1 align="center">
	<br>
	<br>
	<img width="500" src="media/bigint-logo.svg" alt="Bigint">
	<br>
	<br>
	<br>
</h1>


# Bigint
<h5>Big Integer derived from GMP MP</h5>

## Bigint derived from GMP MP. And it doesn't require additional dependencies. Bigint is a simplified version. Convenient syntax, OOP makes the code easy to read.

## Usage

```c++

#include <iostream>
#include "bigint.hpp"

int main(){
	Bigint a, b, c;
	a = 1024;
	b = "1024"; 
	
	c = a + b;
	std::cout << "a + b = " << c << std::endl;
	
	...
	
	c = Bigint::pow(a, b);
	std::cout << "Expower a ^ b = " << c << std::endl;
	
	return 0;
}


```



