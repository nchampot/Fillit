#include "libft_ctypes.h"

const int	g_ctype_arr[DT_CTYPE_ARR_SIZE] =
{
	__C(0, nul, _DT_CNTRL),
	__C(1, soh, _DT_CNTRL),
	__C(2, stx, _DT_CNTRL),
	__C(3, etx, _DT_CNTRL),
	__C(4, eot, _DT_CNTRL),
	__C(5, enq, _DT_CNTRL),
	__C(6, ack, _DT_CNTRL),
	__C(7, bel, _DT_CNTRL),
	__C(8, bs, _DT_CNTRL),
	__C(9, ht, _DT_CNTRL | _DT_SPACE | _DT_BLANK),
	__C(10, nl, _DT_CNTRL | _DT_SPACE),
	__C(11, vt, _DT_CNTRL | _DT_SPACE),
	__C(12, np, _DT_CNTRL | _DT_SPACE),
	__C(13, cr, _DT_CNTRL | _DT_SPACE),
	__C(14, so, _DT_CNTRL),
	__C(15, si, _DT_CNTRL),
	__C(16, dle, _DT_CNTRL),
	__C(17, dc1, _DT_CNTRL),
	__C(18, dc2, _DT_CNTRL),
	__C(19, dc3, _DT_CNTRL),
	__C(20, dc4, _DT_CNTRL),
	__C(21, nak, _DT_CNTRL),
	__C(22, syn, _DT_CNTRL),
	__C(23, etb, _DT_CNTRL),
	__C(24, can, _DT_CNTRL),
	__C(25, em, _DT_CNTRL),
	__C(26, sub, _DT_CNTRL),
	__C(27, esc, _DT_CNTRL),
	__C(28, fs, _DT_CNTRL),
	__C(29, gs, _DT_CNTRL),
	__C(30, rs, _DT_CNTRL),
	__C(31, us, _DT_CNTRL),
	__C(32, sp, _DT_SPACE | _DT_BLANK | _DT_PRINT),
	__C(33, '!', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(34, '"', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(35, '#', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(36, '$', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(37, '%', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(38, '&', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(39, '\'', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(40, '(', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(41, ')', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(42, '*', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(43, '+', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(44, ',', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(45, '-', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(46, '.', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(47, '/', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(48, '0', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(49, '1', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(50, '2', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(51, '3', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(52, '4', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(53, '5', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(54, '6', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(55, '7', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(56, '8', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(57, '9', _DT_DIGIT | _DT_GRAPH | _DT_XDIGIT | _DT_PRINT),
	__C(58, ':', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(59, ';', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(60, '<', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(61, '=', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(62, '>', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(63, '?', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(64, '@', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(65, 'A', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_XDIGIT | _DT_PRINT),
	__C(66, 'B', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_XDIGIT | _DT_PRINT),
	__C(67, 'C', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_XDIGIT | _DT_PRINT),
	__C(68, 'D', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_XDIGIT | _DT_PRINT),
	__C(69, 'E', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_XDIGIT | _DT_PRINT),
	__C(70, 'F', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_XDIGIT | _DT_PRINT),
	__C(71, 'G', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(72, 'H', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(73, 'I', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(74, 'J', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(75, 'K', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(76, 'L', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(77, 'M', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(78, 'N', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(79, 'O', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(80, 'P', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(81, 'Q', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(82, 'R', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(83, 'S', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(84, 'T', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(85, 'U', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(86, 'V', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(87, 'W', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(88, 'X', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(89, 'Y', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(90, 'Z', _DT_ALPHA | _DT_GRAPH | _DT_UPPER | _DT_PRINT),
	__C(91, '[', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(92, '\\', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(93, ']', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(94, '^', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(95, '_', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(96, '`', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(97, 'a', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_XDIGIT | _DT_PRINT),
	__C(98, 'b', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_XDIGIT | _DT_PRINT),
	__C(99, 'c', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_XDIGIT | _DT_PRINT),
	__C(100, 'd', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_XDIGIT | _DT_PRINT),
	__C(101, 'e', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_XDIGIT | _DT_PRINT),
	__C(102, 'f', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_XDIGIT | _DT_PRINT),
	__C(103, 'g', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(104, 'h', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(105, 'i', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(106, 'j', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(107, 'k', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(108, 'l', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(109, 'm', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(110, 'n', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(111, 'o', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(112, 'p', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(113, 'q', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(114, 'r', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(115, 's', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(116, 't', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(117, 'u', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(118, 'v', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(119, 'w', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(120, 'x', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(121, 'y', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(122, 'z', _DT_ALPHA | _DT_GRAPH | _DT_LOWER | _DT_PRINT),
	__C(123, '{', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(124, '|', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(125, '}', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(126, '~', _DT_GRAPH | _DT_PUNCT | _DT_PRINT),
	__C(127, del, _DT_CNTRL),
};
