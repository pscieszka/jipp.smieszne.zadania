#pragma once
struct array
{
	void* data;
	ptr_free free;
	ptr_print print;
	static int last;
};

