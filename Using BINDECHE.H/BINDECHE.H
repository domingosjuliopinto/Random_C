int conversion(binary)
{
	long int binaryval, decimalval = 0, i = 1, remainder;
	binaryval = binary;
	while (binaryval != 0){
	remainder = binaryval % 10;
	decimalval = decimalval + remainder * i;
	i = i * 2;
	binaryval = binaryval / 10;
	}
	return decimalval;
}

void bin_dec(binary)
{
	long int n;
	n=conversion(binary);
	printf("Equivalent decimal value: %ld", n);
}

void bin_hex(binary)
{
	long int n;
	n=conversion(binary);
	printf("Equivalent hexadecimal value: %lX", n);
}