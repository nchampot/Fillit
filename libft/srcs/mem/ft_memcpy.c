#include <string.h>

/*
** The `ft_memcpy()` function copies `n` bytes from memory are `s2` to memory
** area `s1`. If `s` and `s2` overlap, behavior is undefined (in that case, the
** developper would better use ft_memmove()`).
*/
void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*p_s1;
	const char	*p_s2 = s2;

	p_s1 = s1;
	while (n--)
		*p_s1++ = *p_s2++;
	return (s1);
}
