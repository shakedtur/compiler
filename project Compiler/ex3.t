procedure main() return integer{
	
	var int a, b;
	
	a=0;
	while(a<10) {
		b=foo(3.14);
		a=a+b;
	}
}
procedure fan() return void {
	var int a, b;
	
	a=0;
	while(a<10) {
		b=foo(3.14);
		a=a+b;
	}
}

procedure foo(int x) {
	var int a;
	a=23;
	
	if ( a== 23)
		a=10;
	else
		a = 19;
	return x+a;
}
