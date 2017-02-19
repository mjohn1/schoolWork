int main(){

	my_int(my_atoi("")); my_char('\n');
	my_int(my_atoi("hello")); my_char('\n');
	my_int(my_atoi("123hello")); my_char('\n');
	my_int(my_atoi("hello123")); my_char('\n');
	my_int(my_atoi("45.6")); my_char('\n');
	my_int(my_atoi("---34.6")); my_char('\n');
	my_int(my_atoi("--34.6")); my_char('\n');
	my_int(my_atoi("     567")); my_char('\n');
	my_int(my_atoi("   				  567")); my_char('\n');
	my_int(my_atoi("		 5 		 6")); my_char('\n');
	my_int(my_atoi("+34")); my_char('\n');
	my_int(my_atoi("+-+-+-+-+-123")); my_char('\n');
	my_int(my_atoi("+ --    +  --7")); my_char('\n');
	my_int(my_atoi("2147483647")); my_char('\n');
	my_int(my_atoi("-2147483648")); my_char('\n');

	return 0;
}
