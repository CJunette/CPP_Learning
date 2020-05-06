#pragma once


class X;

class Y
{
	public:
	void g(X *x);
};

class Z
{
	public:
	void f(X *x);
};

class X
{
	public:
	int getI() { return i; }

	friend void Y::g(X *x);
	friend class Z;
	friend void h(X *x);

	private:
	int i = 0;
};

void Y::g(X *x)
{
	(*x).i++;
}

void Z::f(X *x)
{
	(*x).i += 5;
}

void h(X *x)
{
	(*x).i += 10;
}