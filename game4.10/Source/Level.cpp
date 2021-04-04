#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Level.h"

#define MAX_BRICK_SIZE	2048
#define MAX_ITEM_SIZE	128


namespace game_framework {
	//int Level1Bricks[][3] = {
	//	// {id, x, y}
	//	{25, 3102, 2714},
	//	{0, 3238, 2714},
	//	{0, 3638, 2714},
	//	{25, 3366, 2713},
	//	{16, 3502, 2713},
	//	{16, 3766, 2713},
	//	{48, 2973, 2691},
	//	{48, 3902, 2690},
	//	{48, 3902, 2665},
	//	{48, 2973, 2647},
	//	{48, 3902, 2625},
	//	{48, 2973, 2599},
	//	{48, 3902, 2585},
	//	{7, 0, 2568},
	//	{7, 128, 2568},
	//	{7, 256, 2568},
	//	{7, 384, 2568},
	//	{7, 512, 2568},
	//	{7, 688, 2568},
	//	{7, 600, 2568},
	//	{16, 816, 2567},
	//	{48, 2973, 2551},
	//	{48, 3902, 2545},
	//	{1, 1455, 2519},
	//	{15, 5284, 2519},
	//	{15, 5944, 2519},
	//	{48, 2973, 2503},
	//	{48, 3902, 2489},
	//	{47, 3367, 2482},
	//	{47, 3605, 2482},
	//	{47, 3367, 2471},
	//	{47, 3605, 2471},
	//	{15, 5284, 2466},
	//	{47, 3367, 2460},
	//	{47, 3399, 2460},
	//	{47, 3432, 2460},
	//	{47, 3465, 2460},
	//	{47, 3497, 2460},
	//	{47, 3530, 2460},
	//	{47, 3562, 2460},
	//	{47, 3594, 2460},
	//	{47, 3605, 2460},
	//	{48, 2973, 2455},
	//	{15, 5944, 2444},
	//	{48, 3902, 2441},
	//	{1, 1455, 2431},
	//	{48, 2973, 2407},
	//	{48, 3902, 2401},
	//	{2, 692, 2392},
	//	{2, 564, 2392},
	//	{2, 437, 2392},
	//	{6, 372, 2391},
	//	{15, 5284, 2386},
	//	{48, 2973, 2367},
	//	{48, 3902, 2353},
	//	{14, 2256, 2349},
	//	{15, 5944, 2344},
	//	{1, 1455, 2343},
	//	{2, 184, 2328},
	//	{2, 136, 2328},
	//	{48, 2973, 2327},
	//	{25, 0, 2327},
	//	{14, 1974, 2313},
	//	{48, 3902, 2305},
	//	{48, 2973, 2279},
	//	{15, 5284, 2279},
	//	{14, 2256, 2269},
	//	{48, 3902, 2268},
	//	{47, 784, 2255},
	//	{47, 752, 2255},
	//	{47, 721, 2255},
	//	{1, 1455, 2255},
	//	{47, 817, 2255},
	//	{47, 849, 2255},
	//	{47, 881, 2255},
	//	{47, 913, 2255},
	//	{47, 921, 2255},
	//	{47, 692, 2255},
	//	{14, 1974, 2253},
	//	{15, 5944, 2249},
	//	{48, 2973, 2245},
	//	{48, 3902, 2212},
	//	{48, 2973, 2197},
	//	{15, 5944, 2184},
	//	{48, 3902, 2172},
	//	{15, 5284, 2169},
	//	{1, 1591, 2168},
	//	{1, 1455, 2167},
	//	{7, 247, 2158},
	//	{7, 375, 2158},
	//	{48, 3902, 2148},
	//	{48, 2973, 2141},
	//	{14, 2256, 2133},
	//	{14, 1974, 2133},
	//	{14, 692, 2119},
	//	{14, 824, 2119},
	//	{14, 756, 2119},
	//	{48, 3902, 2108},
	//	{0, 2103, 2101},
	//	{0, 2128, 2101},
	//	{48, 2973, 2093},
	//	{2, 692, 2087},
	//	{2, 819, 2087},
	//	{2, 825, 2087},
	//	{4, 952, 2087},
	//	{1, 1455, 2080},
	//	{1, 1591, 2080},
	//	{15, 5944, 2079},
	//	{48, 3902, 2060},
	//	{15, 5284, 2049},
	//	{48, 2973, 2045},
	//	{4, 1079, 2023},
	//	{32, 0, 2014},
	//	{47, 136, 2014},
	//	{47, 169, 2014},
	//	{47, 202, 2014},
	//	{47, 235, 2014},
	//	{47, 268, 2014},
	//	{47, 301, 2014},
	//	{47, 332, 2014},
	//	{48, 3902, 2012},
	//	{15, 5944, 2009},
	//	{48, 2973, 1997},
	//	{14, 1974, 1997},
	//	{14, 2256, 1997},
	//	{1, 1455, 1992},
	//	{1, 1591, 1992},
	//	{48, 3902, 1972},
	//	{0, 2972, 1965},
	//	{0, 2851, 1965},
	//	{0, 2723, 1965},
	//	{0, 2613, 1965},
	//	{0, 2513, 1965},
	//	{0, 2448, 1965},
	//	{0, 2383, 1965},
	//	{0, 2257, 1965},
	//	{0, 2256, 1965},
	//	{7, 1207, 1960},
	//	{7, 1335, 1960},
	//	{0, 1448, 1960},
	//	{1, 1591, 1960},
	//	{0, 1567, 1960},
	//	{48, 107, 1958},
	//	{48, 0, 1958},
	//	{15, 5284, 1934},
	//	{48, 3902, 1932},
	//	{15, 5944, 1919},
	//	{14, 1974, 1911},
	//	{16, 3237, 1903},
	//	{48, 108, 1902},
	//	{48, 0, 1902},
	//	{1, 2851, 1901},
	//	{1, 2972, 1901},
	//	{0, 2984, 1901},
	//	{0, 3862, 1901},
	//	{0, 3989, 1901},
	//	{0, 4047, 1901},
	//	{7, 3606, 1901},
	//	{7, 3478, 1901},
	//	{7, 3372, 1901},
	//	{0, 3112, 1901},
	//	{14, 236, 1878},
	//	{1, 1455, 1872},
	//	{1, 1591, 1872},
	//	{48, 107, 1846},
	//	{48, 0, 1846},
	//	{15, 5284, 1829},
	//	{1, 4039, 1813},
	//	{1, 3904, 1813},
	//	{15, 5944, 1809},
	//	{0, 2256, 1803},
	//	{0, 2257, 1803},
	//	{48, 108, 1790},
	//	{48, 0, 1790},
	//	{1, 1591, 1784},
	//	{14, 1974, 1775},
	//	{1, 1591, 1764},
	//	{1, 4039, 1759},
	//	{1, 3904, 1759},
	//	{15, 5284, 1754},
	//	{7, 1847, 1744},
	//	{0, 1975, 1744},
	//	{1, 1591, 1744},
	//	{7, 1727, 1744},
	//	{14, 236, 1742},
	//	{48, 108, 1742},
	//	{48, 0, 1742},
	//	{7, 0, 1712},
	//	{7, 120, 1712},
	//	{7, 237, 1711},
	//	{15, 5944, 1704},
	//	{48, 3991, 1703},
	//	{14, 2256, 1682},
	//	{47, 3102, 1674},
	//	{47, 3340, 1672},
	//	{1, 3904, 1671},
	//	{1, 4039, 1671},
	//	{47, 3102, 1663},
	//	{47, 3340, 1663},
	//	{15, 5284, 1654},
	//	{47, 3102, 1652},
	//	{47, 3134, 1652},
	//	{47, 3166, 1652},
	//	{47, 3198, 1652},
	//	{47, 3230, 1652},
	//	{47, 3262, 1652},
	//	{47, 3295, 1652},
	//	{47, 3328, 1652},
	//	{47, 3340, 1652},
	//	{0, 1847, 1650},
	//	{15, 5944, 1629},
	//	{14, 2256, 1610},
	//	{1, 1847, 1594},
	//	{1, 4040, 1584},
	//	{15, 5284, 1574},
	//	{15, 5944, 1549},
	//	{14, 3244, 1516},
	//	{1, 1847, 1507},
	//	{0, 1719, 1507},
	//	{0, 1591, 1507},
	//	{1, 4040, 1499},
	//	{14, 2256, 1474},
	//	{15, 5284, 1474},
	//	{15, 5944, 1449},
	//	{14, 3244, 1427},
	//	{1, 4040, 1419},
	//	{0, 3693, 1396},
	//	{15, 5284, 1374},
	//	{14, 1590, 1371},
	//	{1, 4040, 1349},
	//	{15, 5944, 1349},
	//	{0, 1971, 1345},
	//	{48, 3692, 1340},
	//	{15, 3244, 1340},
	//	{14, 2256, 1338},
	//	{0, 2257, 1308},
	//	{0, 2187, 1308},
	//	{0, 2107, 1308},
	//	{0, 2099, 1308},
	//	{0, 2383, 1308},
	//	{0, 2498, 1308},
	//	{0, 2623, 1308},
	//	{0, 2728, 1308},
	//	{0, 2838, 1308},
	//	{0, 2938, 1308},
	//	{0, 3053, 1308},
	//	{0, 3178, 1308},
	//	{0, 3303, 1308},
	//	{0, 3353, 1308},
	//	{0, 3468, 1308},
	//	{0, 3588, 1308},
	//	{0, 3693, 1308},
	//	{15, 5284, 1289},
	//	{1, 4040, 1274},
	//	{48, 2864, 1261},
	//	{48, 2735, 1256},
	//	{48, 2649, 1256},
	//	{15, 5944, 1254},
	//	{48, 2993, 1252},
	//	{6, 3301, 1244},
	//	{14, 1590, 1235},
	//	{15, 5284, 1219},
	//	{48, 2735, 1211},
	//	{48, 2864, 1211},
	//	{48, 2993, 1211},
	//	{48, 2649, 1211},
	//	{14, 1970, 1209},
	//	{2, 1718, 1204},
	//	{1, 4040, 1204},
	//	{0, 3111, 1180},
	//	{0, 2986, 1180},
	//	{0, 2861, 1180},
	//	{0, 2735, 1180},
	//	{0, 2649, 1180},
	//	{0, 680, 1176},
	//	{0, 584, 1176},
	//	{0, 472, 1176},
	//	{0, 376, 1176},
	//	{0, 256, 1176},
	//	{0, 128, 1176},
	//	{0, 0, 1176},
	//	{0, 685, 1176},
	//	{48, 2649, 1172},
	//	{15, 5944, 1168},
	//	{7, 4433, 1162},
	//	{7, 4561, 1162},
	//	{7, 4686, 1162},
	//	{7, 4813, 1162},
	//	{6, 4368, 1161},
	//	{15, 5284, 1129},
	//	{14, 1590, 1125},
	//	{1, 4041, 1117},
	//	{48, 2649, 1116},
	//	{6, 4240, 1096},
	//	{14, 1970, 1089},
	//	{0, 1464, 1080},
	//	{0, 1440, 1080},
	//	{0, 1344, 1080},
	//	{0, 1256, 1080},
	//	{0, 1160, 1080},
	//	{0, 1056, 1080},
	//	{0, 936, 1080},
	//	{0, 840, 1080},
	//	{0, 808, 1080},
	//	{2, 1843, 1063},
	//	{48, 2649, 1060},
	//	{15, 5944, 1058},
	//	{15, 6276, 1047},
	//	{15, 684, 1044},
	//	{15, 5284, 1039},
	//	{14, 1590, 1035},
	//	{0, 3917, 1032},
	//	{0, 3802, 1032},
	//	{0, 3702, 1032},
	//	{0, 3597, 1032},
	//	{0, 3507, 1032},
	//	{0, 3422, 1032},
	//	{0, 3337, 1032},
	//	{0, 3237, 1032},
	//	{0, 3137, 1032},
	//	{0, 3037, 1032},
	//	{1, 4041, 1032},
	//	{0, 3001, 1032},
	//	{48, 2648, 1004},
	//	{1, 812, 995},
	//	{1, 931, 995},
	//	{1, 1065, 995},
	//	{1, 1201, 995},
	//	{14, 1970, 984},
	//	{2, 3282, 967},
	//	{15, 5944, 948},
	//	{0, 2448, 948},
	//	{48, 2648, 948},
	//	{15, 6276, 947},
	//	{0, 2520, 947},
	//	{6, 2383, 946},
	//	{15, 5284, 944},
	//	{48, 6405, 942},
	//	{48, 6662, 942},
	//	{48, 6920, 942},
	//	{48, 6533, 941},
	//	{48, 6790, 941},
	//	{48, 6922, 940},
	//	{14, 1590, 930},
	//	{1, 7866, 918},
	//	{1, 7730, 918},
	//	{1, 7594, 918},
	//	{1, 7458, 918},
	//	{1, 7322, 918},
	//	{1, 7186, 918},
	//	{1, 7050, 916},
	//	{15, 684, 908},
	//	{1, 812, 907},
	//	{1, 931, 907},
	//	{1, 1065, 907},
	//	{1, 1201, 907},
	//	{48, 6922, 900},
	//	{0, 1591, 899},
	//	{0, 1589, 899},
	//	{6, 1525, 899},
	//	{48, 2648, 892},
	//	{14, 1970, 889},
	//	{48, 2648, 889},
	//	{48, 6405, 886},
	//	{48, 6662, 886},
	//	{48, 6920, 886},
	//	{48, 6533, 885},
	//	{48, 6791, 885},
	//	{6, 2255, 882},
	//	{2, 4901, 870},
	//	{4, 5029, 868},
	//	{15, 5944, 863},
	//	{0, 2449, 858},
	//	{0, 2564, 858},
	//	{0, 2689, 858},
	//	{0, 2784, 858},
	//	{0, 2914, 858},
	//	{0, 2989, 858},
	//	{0, 3089, 858},
	//	{0, 3194, 858},
	//	{0, 3304, 858},
	//	{0, 3414, 858},
	//	{0, 3509, 858},
	//	{0, 3609, 858},
	//	{0, 3719, 858},
	//	{0, 3804, 858},
	//	{0, 3904, 858},
	//	{0, 4029, 858},
	//	{0, 2874, 858},
	//	{15, 6276, 857},
	//	{15, 5284, 854},
	//	{14, 1970, 849},
	//	{0, 1336, 835},
	//	{48, 6405, 830},
	//	{48, 6533, 830},
	//	{48, 6662, 830},
	//	{48, 6791, 830},
	//	{48, 6920, 830},
	//	{48, 6922, 830},
	//	{1, 7186, 830},
	//	{1, 7322, 830},
	//	{1, 7458, 830},
	//	{1, 7594, 830},
	//	{1, 7730, 830},
	//	{1, 7866, 830},
	//	{1, 7050, 829},
	//	{15, 684, 820},
	//	{1, 813, 819},
	//	{1, 948, 819},
	//	{1, 1201, 819},
	//	{1, 1082, 819},
	//	{0, 2064, 818},
	//	{0, 1949, 818},
	//	{4, 5157, 805},
	//	{48, 2450, 803},
	//	{48, 2579, 802},
	//	{48, 2664, 802},
	//	{48, 2749, 802},
	//	{48, 2834, 802},
	//	{48, 2909, 802},
	//	{48, 2989, 802},
	//	{48, 3069, 802},
	//	{48, 3154, 802},
	//	{48, 3229, 802},
	//	{48, 3304, 802},
	//	{48, 3389, 802},
	//	{48, 3479, 802},
	//	{48, 3574, 802},
	//	{48, 3649, 802},
	//	{48, 3739, 802},
	//	{48, 3814, 802},
	//	{48, 3886, 802},
	//	{48, 3902, 802},
	//	{15, 5284, 774},
	//	{15, 6276, 773},
	//	{15, 5944, 773},
	//	{48, 2450, 748},
	//	{48, 2670, 746},
	//	{48, 2760, 746},
	//	{48, 2850, 746},
	//	{48, 2920, 746},
	//	{48, 2995, 746},
	//	{48, 3090, 746},
	//	{48, 3180, 746},
	//	{48, 3265, 746},
	//	{48, 3350, 746},
	//	{48, 3425, 746},
	//	{48, 3500, 746},
	//	{48, 3575, 746},
	//	{48, 3665, 746},
	//	{48, 3740, 746},
	//	{48, 3830, 746},
	//	{48, 3902, 746},
	//	{48, 2577, 746},
	//	{7, 5817, 742},
	//	{7, 5812, 742},
	//	{7, 5797, 742},
	//	{7, 5669, 742},
	//	{7, 5541, 742},
	//	{7, 5413, 742},
	//	{0, 6277, 742},
	//	{0, 6271, 742},
	//	{0, 6166, 742},
	//	{0, 6071, 742},
	//	{2, 5285, 742},
	//	{2, 5944, 742},
	//	{1, 6405, 742},
	//	{1, 6534, 742},
	//	{1, 6663, 742},
	//	{1, 6792, 742},
	//	{1, 6921, 742},
	//	{1, 7050, 742},
	//	{1, 7186, 742},
	//	{1, 7322, 742},
	//	{1, 7458, 742},
	//	{1, 7594, 742},
	//	{1, 7730, 742},
	//	{1, 7866, 742},
	//	{0, 1046, 725},
	//	{0, 1971, 725},
	//	{0, 1851, 725},
	//	{0, 1756, 725},
	//	{0, 1676, 725},
	//	{0, 1591, 725},
	//	{0, 1511, 725},
	//	{0, 1446, 725},
	//	{0, 1381, 725},
	//	{0, 1291, 725},
	//	{0, 1231, 725},
	//	{0, 1171, 725},
	//	{0, 1106, 725},
	//	{14, 4029, 722},
	//	{48, 2450, 694},
	//	{48, 2579, 692},
	//	{48, 2668, 692},
	//	{48, 2743, 692},
	//	{48, 2813, 692},
	//	{48, 2883, 692},
	//	{48, 2953, 692},
	//	{48, 3023, 692},
	//	{48, 3093, 692},
	//	{48, 3173, 692},
	//	{48, 3253, 692},
	//	{48, 3323, 692},
	//	{48, 3413, 692},
	//	{48, 3493, 692},
	//	{48, 3573, 692},
	//	{48, 3643, 692},
	//	{48, 3723, 692},
	//	{48, 3793, 692},
	//	{48, 3863, 692},
	//	{48, 3900, 692},
	//	{15, 684, 684},
	//	{48, 1175, 669},
	//	{48, 1255, 669},
	//	{48, 1335, 669},
	//	{48, 1415, 669},
	//	{48, 1505, 669},
	//	{48, 1580, 669},
	//	{48, 1655, 669},
	//	{48, 1730, 669},
	//	{48, 1815, 669},
	//	{48, 1841, 669},
	//	{0, 3901, 661},
	//	{0, 3851, 661},
	//	{0, 3781, 661},
	//	{0, 3686, 661},
	//	{0, 3606, 661},
	//	{48, 2450, 649},
	//	{0, 6277, 648},
	//	{0, 6276, 648},
	//	{48, 2579, 637},
	//	{48, 2639, 637},
	//	{48, 2729, 637},
	//	{48, 2799, 637},
	//	{48, 2928, 637},
	//	{48, 2450, 624},
	//	{14, 4029, 617},
	//	{48, 2580, 613},
	//	{48, 2640, 613},
	//	{48, 2708, 613},
	//	{48, 2778, 613},
	//	{48, 2907, 613},
	//	{48, 1842, 613},
	//	{48, 1722, 613},
	//	{48, 1607, 613},
	//	{48, 1512, 613},
	//	{48, 1422, 613},
	//	{48, 1302, 613},
	//	{48, 1207, 613},
	//	{48, 1175, 613},
	//	{14, 1970, 591},
	//	{15, 684, 589},
	//	{15, 1046, 589},
	//	{48, 2451, 583},
	//	{0, 2829, 582},
	//	{0, 2709, 582},
	//	{0, 2579, 582},
	//	{0, 2582, 582},
	//	{48, 1432, 558},
	//	{0, 1047, 557},
	//	{0, 1040, 557},
	//	{0, 969, 557},
	//	{0, 879, 557},
	//	{0, 784, 557},
	//	{0, 684, 557},
	//	{48, 1175, 557},
	//	{48, 1304, 557},
	//	{48, 1841, 557},
	//	{48, 1731, 557},
	//	{48, 1631, 557},
	//	{48, 1532, 557},
	//	{0, 2451, 552},
	//	{0, 2462, 552},
	//	{15, 6276, 537},
	//	{48, 1432, 502},
	//	{48, 1842, 502},
	//	{48, 1175, 501},
	//	{48, 1055, 501},
	//	{48, 940, 501},
	//	{48, 835, 501},
	//	{48, 725, 501},
	//	{48, 684, 501},
	//	{48, 1303, 501},
	//	{14, 4029, 482},
	//	{14, 1970, 481},
	//	{47, 6783, 457},
	//	{47, 7050, 457},
	//	{14, 2580, 447},
	//	{47, 6783, 447},
	//	{47, 7050, 447},
	//	{48, 1341, 446},
	//	{48, 1841, 446},
	//	{48, 684, 445},
	//	{48, 812, 445},
	//	{48, 887, 445},
	//	{48, 972, 445},
	//	{48, 1042, 445},
	//	{48, 1117, 445},
	//	{48, 1212, 445},
	//	{47, 6783, 436},
	//	{47, 6816, 436},
	//	{47, 6849, 436},
	//	{47, 6882, 436},
	//	{47, 6915, 436},
	//	{47, 6948, 436},
	//	{47, 6981, 436},
	//	{47, 7014, 436},
	//	{47, 7047, 436},
	//	{47, 7050, 436},
	//	{68, 7381, 435},
	//	{2, 7874, 435},
	//	{2, 7746, 435},
	//	{0, 2451, 431},
	//	{0, 2452, 431},
	//	{14, 2580, 431},
	//	{15, 6276, 402},
	//	{0, 2580, 399},
	//	{0, 2581, 399},
	//	{48, 1841, 391},
	//	{14, 1970, 386},
	//	{14, 4029, 347},
	//	{48, 1841, 335},
	//	{14, 2451, 325},
	//	{14, 1970, 296},
	//	{48, 1842, 279},
	//	{15, 6276, 267},
	//	{14, 4029, 237},
	//	{0, 3902, 237},
	//	{48, 1842, 223},
	//	{14, 1970, 216},
	//	{0, 4030, 205},
	//	{14, 2451, 190},
	//	{48, 1842, 167},
	//	{15, 6276, 131},
	//	{48, 1842, 112},
	//	{0, 4031, 104},
	//	{0, 4032, 104},
	//	{14, 3903, 102},
	//	{14, 1970, 91},
	//	{0, 3903, 72},
	//	{14, 2451, 65},
	//	{48, 1841, 56},
	//	{15, 6276, 46},
	//	{15, 6276, 0},
	//	{14, 1970, 0},
	//	{14, 2451, 0},
	//	{14, 4031, 0},
	//	{48, 1842, 0},
	//	{26, 3187, 2698},
	//	{17, 3769, 2697},
	//	{26, 3449, 2697},
	//	{17, 3505, 2697},
	//	{27, 3157, 2669},
	//	{18, 3818, 2669},
	//	{18, 3554, 2669},
	//	{27, 3421, 2668},
	//	{19, 3582, 2612},
	//	{28, 3141, 2610},
	//	{31, 3102, 2610},
	//	{22, 3862, 2610},
	//	{19, 3846, 2610},
	//	{28, 3405, 2609},
	//	{31, 3366, 2609},
	//	{22, 3598, 2609},
	//	{23, 3598, 2598},
	//	{23, 3605, 2598},
	//	{24, 3373, 2595},
	//	{24, 3366, 2595},
	//	{17, 818, 2552},
	//	{42, 3583, 2536},
	//	{35, 3405, 2535},
	//	{18, 869, 2524},
	//	{41, 3555, 2508},
	//	{34, 3420, 2507},
	//	{71, 3101, 2506},
	//	{70, 3862, 2506},
	//	{45, 3598, 2493},
	//	{33, 3448, 2493},
	//	{40, 3504, 2493},
	//	{38, 3366, 2491},
	//	{19, 897, 2465},
	//	{22, 912, 2465},
	//	{23, 912, 2432},
	//	{23, 920, 2432},
	//	{23, 920, 2424},
	//	{71, 3101, 2402},
	//	{70, 3862, 2402},
	//	{23, 912, 2399},
	//	{23, 912, 2391},
	//	{23, 919, 2391},
	//	{42, 896, 2332},
	//	{5, 309, 2327},
	//	{26, 83, 2311},
	//	{41, 868, 2303},
	//	{71, 3101, 2298},
	//	{70, 3862, 2298},
	//	{40, 817, 2288},
	//	{45, 912, 2287},
	//	{27, 54, 2283},
	//	{28, 39, 2224},
	//	{31, 0, 2223},
	//	{71, 3101, 2194},
	//	{70, 3862, 2194},
	//	{24, 7, 2190},
	//	{24, 0, 2190},
	//	{24, 7, 2157},
	//	{24, 0, 2157},
	//	{24, 7, 2151},
	//	{24, 0, 2150},
	//	{71, 3101, 2090},
	//	{35, 40, 2090},
	//	{70, 3862, 2090},
	//	{34, 55, 2062},
	//	{38, 0, 2047},
	//	{33, 85, 2047},
	//	{3, 953, 2023},
	//	{71, 3101, 1986},
	//	{70, 3862, 1986},
	//	{3, 1080, 1959},
	//	{70, 3862, 1931},
	//	{10, 2724, 1901},
	//	{17, 3239, 1887},
	//	{71, 3101, 1882},
	//	{18, 3290, 1859},
	//	{19, 3319, 1801},
	//	{22, 3333, 1799},
	//	{71, 3101, 1778},
	//	{23, 3332, 1774},
	//	{23, 3340, 1774},
	//	{42, 3318, 1726},
	//	{35, 3141, 1726},
	//	{41, 3290, 1698},
	//	{34, 3157, 1698},
	//	{40, 3240, 1683},
	//	{33, 3185, 1683},
	//	{38, 3101, 1683},
	//	{45, 3333, 1682},
	//	{5, 3365, 1244},
	//	{5, 3238, 1180},
	//	{17, 4809, 1146},
	//	{18, 4860, 1117},
	//	{5, 4305, 1097},
	//	{19, 4888, 1059},
	//	{22, 4901, 1058},
	//	{5, 4177, 1032},
	//	{23, 4908, 1026},
	//	{23, 4901, 1026},
	//	{23, 4908, 995},
	//	{23, 4901, 995},
	//	{3, 3155, 968},
	//	{5, 3410, 968},
	//	{23, 4908, 963},
	//	{23, 4901, 963},
	//	{23, 4901, 932},
	//	{23, 4908, 931},
	//	{23, 4908, 901},
	//	{23, 4901, 900},
	//	{5, 2320, 882},
	//	{5, 1463, 835},
	//	{5, 2192, 818},
	//	{3, 5030, 804},
	//	{3, 5158, 741},
	//	{26, 6865, 726},
	//	{17, 6948, 726},
	//	{27, 6837, 697},
	//	{18, 6999, 697},
	//	{28, 6822, 638},
	//	{31, 6782, 638},
	//	{19, 7028, 638},
	//	{22, 7043, 638},
	//	{24, 6790, 605},
	//	{23, 7043, 605},
	//	{24, 6782, 605},
	//	{23, 7050, 605},
	//	{24, 6790, 572},
	//	{23, 7043, 572},
	//	{24, 6783, 572},
	//	{23, 7050, 572},
	//	{42, 7027, 513},
	//	{35, 6823, 511},
	//	{41, 6998, 484},
	//	{34, 6839, 483},
	//	{38, 6783, 468},
	//	{33, 6867, 468},
	//	{45, 7043, 468},
	//	{40, 6947, 468},
	//	{72, 503, 2158},
	//	{72, 631, 2158},
	//	{72, 3734, 1901},
	//	{72, 3776, 1671},
	//	{72, 3970, 1419},
	//	{72, 2888, 1032},
	//	{72, 2776, 1032},
	//	{29, 3142, 2698},
	//	{20, 3817, 2698},
	//	{29, 3406, 2697},
	//	{20, 3553, 2697},
	//	{21, 3583, 2671},
	//	{30, 3141, 2669},
	//	{21, 3846, 2669},
	//	{30, 3405, 2668},
	//	{62, 3282, 2586},
	//	{62, 3678, 2586},
	//	{20, 867, 2553},
	//	{51, 225, 2543},
	//	{51, 46, 2543},
	//	{56, 671, 2536},
	//	{21, 897, 2524},
	//	{64, 156, 2519},
	//	{44, 3583, 2508},
	//	{37, 3405, 2507},
	//	{43, 3553, 2493},
	//	{36, 3406, 2491},
	//	{52, 430, 2473},
	//	{50, 865, 2448},
	//	{50, 36, 2441},
	//	{50, 207, 2440},
	//	{59, 748, 2431},
	//	{64, 3489, 2410},
	//	{59, 119, 2409},
	//	{59, 226, 2401},
	//	{51, 490, 2369},
	//	{29, 40, 2311},
	//	{51, 219, 2304},
	//	{44, 896, 2303},
	//	{43, 867, 2287},
	//	{30, 39, 2283},
	//	{51, 219, 2280},
	//	{61, 556, 2266},
	//	{50, 471, 2264},
	//	{61, 145, 2202},
	//	{59, 252, 2187},
	//	{57, 255, 2134},
	//	{58, 263, 2134},
	//	{57, 319, 2134},
	//	{58, 327, 2134},
	//	{57, 383, 2134},
	//	{58, 391, 2134},
	//	{57, 447, 2134},
	//	{58, 455, 2134},
	//	{57, 511, 2134},
	//	{58, 519, 2134},
	//	{57, 574, 2134},
	//	{58, 582, 2134},
	//	{57, 637, 2134},
	//	{58, 645, 2134},
	//	{56, 522, 2126},
	//	{66, 448, 2107},
	//	{51, 710, 2063},
	//	{51, 800, 2063},
	//	{53, 694, 2063},
	//	{54, 708, 2063},
	//	{54, 734, 2063},
	//	{54, 761, 2063},
	//	{54, 788, 2063},
	//	{54, 814, 2063},
	//	{54, 834, 2063},
	//	{54, 862, 2063},
	//	{54, 884, 2063},
	//	{55, 899, 2063},
	//	{37, 40, 2061},
	//	{36, 40, 2047},
	//	{63, 164, 2047},
	//	{51, 800, 2039},
	//	{59, 401, 1992},
	//	{60, 538, 1989},
	//	{60, 896, 1951},
	//	{60, 589, 1943},
	//	{51, 2462, 1941},
	//	{51, 2627, 1941},
	//	{56, 1221, 1928},
	//	{51, 2627, 1917},
	//	{60, 777, 1893},
	//	{20, 3288, 1887},
	//	{50, 2327, 1886},
	//	{51, 3626, 1878},
	//	{21, 3319, 1860},
	//	{50, 1394, 1856},
	//	{51, 3626, 1855},
	//	{66, 3813, 1851},
	//	{50, 2406, 1837},
	//	{50, 1315, 1832},
	//	{66, 1479, 1822},
	//	{59, 2495, 1799},
	//	{59, 2585, 1799},
	//	{59, 2680, 1799},
	//	{59, 2780, 1773},
	//	{59, 2875, 1735},
	//	{59, 3542, 1735},
	//	{59, 3410, 1735},
	//	{59, 3759, 1735},
	//	{50, 1394, 1728},
	//	{51, 1896, 1721},
	//	{37, 3141, 1698},
	//	{44, 3319, 1697},
	//	{67, 2044, 1693},
	//	{51, 216, 1688},
	//	{51, 32, 1688},
	//	{36, 3141, 1683},
	//	{43, 3288, 1682},
	//	{52, 1624, 1649},
	//	{66, 3924, 1621},
	//	{52, 296, 1616},
	//	{50, 24, 1592},
	//	{50, 136, 1592},
	//	{52, 3982, 1575},
	//	{59, 224, 1545},
	//	{60, 66, 1516},
	//	{58, 1719, 1483},
	//	{57, 1774, 1483},
	//	{58, 1782, 1483},
	//	{57, 1837, 1483},
	//	{58, 1845, 1483},
	//	{57, 1901, 1483},
	//	{58, 1909, 1483},
	//	{57, 1964, 1483},
	//	{61, 1722, 1382},
	//	{65, 3991, 1371},
	//	{59, 1875, 1341},
	//	{57, 3485, 1285},
	//	{57, 3801, 1284},
	//	{58, 3745, 1284},
	//	{57, 3738, 1284},
	//	{58, 3682, 1284},
	//	{57, 3674, 1284},
	//	{58, 3618, 1284},
	//	{57, 3612, 1284},
	//	{58, 3556, 1284},
	//	{57, 3549, 1284},
	//	{58, 3493, 1284},
	//	{51, 1780, 1182},
	//	{57, 2842, 1157},
	//	{58, 2786, 1157},
	//	{57, 2779, 1157},
	//	{57, 3224, 1156},
	//	{58, 3168, 1156},
	//	{57, 3160, 1156},
	//	{58, 3104, 1156},
	//	{57, 3097, 1156},
	//	{58, 3041, 1156},
	//	{57, 3032, 1156},
	//	{58, 2976, 1156},
	//	{57, 2969, 1156},
	//	{58, 2913, 1156},
	//	{57, 2905, 1156},
	//	{58, 2849, 1156},
	//	{56, 3040, 1148},
	//	{20, 4860, 1146},
	//	{59, 3564, 1142},
	//	{59, 3704, 1142},
	//	{53, 4438, 1138},
	//	{54, 4453, 1138},
	//	{54, 4481, 1138},
	//	{54, 4509, 1138},
	//	{54, 4536, 1138},
	//	{54, 4564, 1138},
	//	{54, 4591, 1138},
	//	{54, 4619, 1138},
	//	{54, 4642, 1138},
	//	{54, 4669, 1138},
	//	{54, 4697, 1138},
	//	{54, 4725, 1138},
	//	{54, 4753, 1138},
	//	{54, 4781, 1138},
	//	{55, 4803, 1138},
	//	{21, 4889, 1118},
	//	{59, 1793, 1070},
	//	{59, 1730, 1040},
	//	{61, 4469, 1036},
	//	{61, 4719, 1036},
	//	{61, 4593, 1036},
	//	{65, 1885, 1014},
	//	{58, 3062, 1009},
	//	{58, 3687, 1009},
	//	{57, 2992, 1008},
	//	{58, 3000, 1008},
	//	{57, 3054, 1008},
	//	{57, 3118, 1008},
	//	{57, 3553, 1008},
	//	{58, 3561, 1008},
	//	{57, 3616, 1008},
	//	{57, 3679, 1008},
	//	{57, 3742, 1008},
	//	{58, 3750, 1008},
	//	{57, 3806, 1008},
	//	{58, 3814, 1008},
	//	{57, 3870, 1008},
	//	{58, 3878, 1008},
	//	{57, 3934, 1008},
	//	{58, 3941, 1008},
	//	{57, 3996, 1008},
	//	{58, 4004, 1008},
	//	{57, 4060, 1008},
	//	{58, 4068, 1008},
	//	{57, 4123, 1008},
	//	{58, 3624, 1007},
	//	{61, 4262, 992},
	//	{51, 3285, 943},
	//	{59, 1918, 898},
	//	{59, 3822, 896},
	//	{59, 3587, 896},
	//	{59, 4094, 895},
	//	{63, 3650, 890},
	//	{51, 1662, 875},
	//	{51, 1599, 875},
	//	{49, 2471, 871},
	//	{63, 3917, 854},
	//	{51, 1663, 851},
	//	{8, 1081, 811},
	//	{8, 839, 810},
	//	{8, 813, 810},
	//	{55, 2157, 794},
	//	{54, 2132, 794},
	//	{54, 2104, 794},
	//	{54, 2076, 794},
	//	{54, 2049, 794},
	//	{54, 2021, 794},
	//	{54, 1993, 794},
	//	{53, 1978, 794},
	//	{56, 896, 787},
	//	{59, 2377, 772},
	//	{50, 2038, 733},
	//	{29, 6820, 726},
	//	{20, 6999, 726},
	//	{52, 2121, 722},
	//	{59, 2276, 722},
	//	{51, 7864, 718},
	//	{51, 6064, 718},
	//	{51, 6154, 718},
	//	{57, 7246, 718},
	//	{58, 7254, 718},
	//	{57, 7309, 718},
	//	{58, 7317, 718},
	//	{57, 7371, 718},
	//	{58, 7379, 718},
	//	{57, 7433, 718},
	//	{58, 7441, 718},
	//	{57, 7497, 718},
	//	{58, 7505, 718},
	//	{57, 7560, 718},
	//	{58, 7568, 718},
	//	{57, 7622, 718},
	//	{58, 7630, 718},
	//	{57, 7685, 718},
	//	{57, 7749, 718},
	//	{57, 7811, 718},
	//	{58, 7819, 718},
	//	{57, 7873, 718},
	//	{58, 7881, 718},
	//	{57, 7935, 718},
	//	{57, 7994, 718},
	//	{58, 7190, 718},
	//	{57, 7182, 718},
	//	{58, 7693, 717},
	//	{58, 7757, 717},
	//	{58, 7943, 717},
	//	{56, 7589, 710},
	//	{59, 4913, 704},
	//	{30, 6822, 697},
	//	{21, 7028, 697},
	//	{51, 6154, 694},
	//	{64, 5337, 692},
	//	{62, 844, 691},
	//	{59, 2205, 688},
	//	{60, 900, 685},
	//	{50, 6568, 678},
	//	{60, 4968, 675},
	//	{49, 6279, 660},
	//	{50, 7842, 627},
	//	{60, 955, 623},
	//	{61, 5280, 617},
	//	{61, 5945, 617},
	//	{62, 5789, 616},
	//	{62, 5649, 616},
	//	{62, 5518, 616},
	//	{62, 7195, 614},
	//	{62, 7310, 614},
	//	{62, 7420, 614},
	//	{62, 7535, 614},
	//	{62, 7655, 614},
	//	{62, 7785, 614},
	//	{62, 7920, 614},
	//	{50, 6469, 614},
	//	{50, 7842, 595},
	//	{59, 6880, 576},
	//	{60, 6913, 547},
	//	{58, 2496, 528},
	//	{57, 2488, 528},
	//	{57, 2551, 528},
	//	{44, 7027, 485},
	//	{37, 6823, 482},
	//	{52, 2455, 477},
	//	{36, 6823, 468},
	//	{43, 6998, 468},
	//	{50, 7842, 467},
	//	{51, 6835, 412},
	//	{64, 7018, 386},
	//	{50, 7902, 339},
	//	{52, 7842, 339},
	//	{50, 7762, 307},
	//	{52, 4091, 147},
	//	{46, 3487, 2471},
	//	{46, 3520, 2471},
	//	{46, 3456, 2471},
	//	{46, 3553, 2471},
	//	{46, 3585, 2471},
	//	{46, 3423, 2471},
	//	{46, 3390, 2471},
	//	{46, 784, 2266},
	//	{46, 752, 2266},
	//	{46, 720, 2266},
	//	{46, 815, 2266},
	//	{46, 847, 2266},
	//	{46, 879, 2266},
	//	{46, 910, 2266},
	//	{46, 692, 2266},
	//	{46, 920, 2265},
	//	{46, 136, 2025},
	//	{46, 169, 2025},
	//	{46, 202, 2025},
	//	{46, 235, 2025},
	//	{46, 267, 2025},
	//	{46, 300, 2025},
	//	{46, 332, 2025},
	//	{46, 3123, 1663},
	//	{46, 3221, 1663},
	//	{46, 3253, 1663},
	//	{46, 3188, 1663},
	//	{46, 3286, 1663},
	//	{46, 3155, 1663},
	//	{46, 3318, 1663},
	//	{46, 6792, 446},
	//	{46, 6824, 446},
	//	{46, 6854, 446},
	//	{46, 6879, 446},
	//	{46, 6908, 446},
	//	{46, 6941, 446},
	//	{46, 6974, 446},
	//	{46, 7007, 446},
	//	{46, 7040, 446},
	//	{69, 3804, 2651},
	//	{69, 3109, 2647},
	//	{69, 3204, 2647},
	//	{69, 3710, 2642},
	//	{69, 3522, 2642},
	//	{69, 3426, 2642},
	//	{69, 3330, 2642},
	//	{69, 3235, 2642},
	//	{69, 3617, 2634},
	//	{69, 3805, 2571},
	//	{69, 3108, 2569},
	//	{69, 3204, 2569},
	//	{69, 3711, 2563},
	//	{69, 3520, 2562},
	//	{69, 3424, 2562},
	//	{69, 3328, 2562},
	//	{69, 3232, 2562},
	//	{69, 3617, 2555},
	//	{69, 3805, 2491},
	//	{69, 3108, 2489},
	//	{69, 3204, 2489},
	//	{69, 3488, 2484},
	//	{69, 3711, 2483},
	//	{69, 3678, 2483},
	//	{69, 3580, 2483},
	//	{69, 3582, 2483},
	//	{69, 3299, 2482},
	//	{69, 3392, 2482},
	//	{69, 3805, 2411},
	//	{69, 3108, 2409},
	//	{69, 3204, 2409},
	//	{69, 3711, 2403},
	//	{69, 3615, 2403},
	//	{69, 3519, 2403},
	//	{69, 3423, 2403},
	//	{69, 3300, 2402},
	//	{69, 3328, 2402},
	//	{69, 3805, 2331},
	//	{69, 3108, 2329},
	//	{69, 3204, 2329},
	//	{69, 3550, 2323},
	//	{69, 3711, 2323},
	//	{69, 3615, 2323},
	//	{69, 3388, 2323},
	//	{69, 3482, 2323},
	//	{69, 3300, 2322},
	//	{69, 3805, 2251},
	//	{69, 3109, 2249},
	//	{69, 3204, 2249},
	//	{69, 3549, 2243},
	//	{69, 3711, 2243},
	//	{69, 3615, 2243},
	//	{69, 3394, 2243},
	//	{69, 3490, 2243},
	//	{69, 3549, 2242},
	//	{69, 3300, 2242},
	//	{69, 3805, 2171},
	//	{69, 3109, 2169},
	//	{69, 3204, 2169},
	//	{69, 3711, 2163},
	//	{69, 3615, 2163},
	//	{69, 3396, 2163},
	//	{69, 3492, 2163},
	//	{69, 3300, 2162},
	//	{69, 3587, 2162},
	//	{69, 3806, 2091},
	//	{69, 3109, 2090},
	//	{69, 3395, 2090},
	//	{69, 3204, 2089},
	//	{69, 3491, 2085},
	//	{69, 3712, 2083},
	//	{69, 3617, 2083},
	//	{69, 3300, 2083},
	//	{69, 3301, 2083},
	//	{69, 3553, 2083},
	//	{69, 3805, 2011},
	//	{69, 3775, 2011},
	//	{69, 3681, 2011},
	//	{69, 3588, 2011},
	//	{69, 3493, 2011},
	//	{69, 3397, 2011},
	//	{69, 3301, 2011},
	//	{69, 3300, 2011},
	//	{69, 3108, 2011},
	//	{69, 3204, 2011},
	//	{69, 3777, 1932},
	//	{69, 3681, 1932},
	//	{69, 3586, 1932},
	//	{69, 3491, 1932},
	//	{69, 3806, 1931},
	//	{69, 3396, 1931},
	//	{69, 3301, 1931},
	//	{69, 3205, 1931},
	//	{69, 3109, 1931}
	//};

	//int Level1Items[][3] = {
	//	// {id, x, y}
	//	{0, 3843, 1290},
	//	{69, 1840, 1664},
	//	{50, 364, 1892},
	//	{0, 2180, 1708},
	//	{0, 2126, 1709},
	//	{0, 2069, 1708},
	//	{0, 2016, 1708},
	//	{20, 1422, 1960},
	//	{21, 639, 2392},
	//	{27, 3840, 1671},
	//	{0, 4879, 842},
	//	{0, 4878, 792},
	//	{1, 2617, 947},
	//	{1, 3227, 1652},
	//	{25, 3968, 1670},
	//	{0, 338, 2550},
	//	{19, 3665, 2618},
	//	{19, 3665, 2526},
	//	{19, 3666, 2434},
	//	{19, 3636, 2433},
	//	{19, 3306, 2619},
	//	{19, 3307, 2527},
	//	{19, 3308, 2434},
	//	{19, 3338, 2434},
	//	{18, 3635, 2527},
	//	{18, 3635, 2620},
	//	{16, 3337, 2529},
	//	{16, 3336, 2620},
	//	{20, 2828, 1179},
	//	{35, 3207, 1682},
	//	{19, 3351, 1920},
	//	{19, 3324, 1919},
	//	{33, 3183, 1682},
	//	{34, 3259, 1681},
	//	{33, 3188, 2001},
	//	{33, 3169, 1998},
	//	{33, 3140, 1999},
	//	{34, 3127, 2028},
	//	{34, 3152, 2029},
	//	{34, 3182, 2029},
	//	{34, 3213, 2029},
	//	{34, 3212, 2000},
	//	{34, 3213, 1914},
	//	{34, 3213, 1942},
	//	{34, 3212, 1971},
	//	{19, 3041, 1805},
	//	{19, 3040, 1711},
	//	{19, 3042, 1619},
	//	{16, 3071, 1713},
	//	{16, 3071, 1806},
	//	{0, 1067, 2000},
	//	{0, 2780, 1913},
	//	{0, 2834, 1885},
	//	{31, 7767, 740},
	//	{0, 865, 801},
	//	{0, 936, 801},
	//	{0, 1011, 801},
	//	{0, 1076, 801},
	//	{28, 927, 684},
	//	{1, 2521, 552},
	//	{26, 6378, 678},
	//	{25, 6285, 741},
	//	{25, 1865, 1743},
	//	{26, 1949, 1680},
	//	{26, 1106, 754},
	//	{21, 2125, 2101},
	//	{20, 2235, 2101},
	//	{16, 6753, 648},
	//	{16, 6753, 583},
	//	{16, 6753, 513},
	//	{16, 6753, 463},
	//	{16, 6753, 393},
	//	{17, 6917, 468},
	//	{18, 7082, 398},
	//	{18, 7082, 478},
	//	{18, 7082, 558},
	//	{18, 7082, 643},
	//	{18, 7082, 678},
	//	{19, 7109, 400},
	//	{19, 7109, 470},
	//	{19, 7109, 545},
	//	{19, 7109, 610},
	//	{19, 7109, 660},
	//	{19, 6722, 660},
	//	{19, 6722, 595},
	//	{19, 6722, 515},
	//	{19, 6722, 435},
	//	{19, 6722, 385},
	//	{19, 6752, 352},
	//	{19, 6754, 352},
	//	{19, 7080, 353},
	//	{19, 7089, 355},
	//	{19, 6732, 363},
	//	{19, 7100, 374},
	//	{24, 2016, 1661},
	//	{24, 2016, 1601},
	//	{24, 2016, 1541},
	//	{24, 2016, 1481},
	//	{24, 1946, 1481},
	//	{24, 1886, 1481},
	//	{24, 1816, 1481},
	//	{24, 1746, 1481},
	//	{24, 1746, 1411},
	//	{24, 1746, 1351},
	//	{24, 1746, 1301},
	//	{2, 7889, 435},
	//	{2, 7949, 435},
	//	{2, 7837, 435},
	//	{2, 6935, 436},
	//	{1, 4071, 206},
	//	{24, 6756, 414},
	//	{24, 6681, 414},
	//	{24, 6601, 414},
	//	{24, 6521, 414},
	//	{24, 6449, 415},
	//	{24, 6419, 466},
	//	{24, 6419, 546},
	//	{24, 6419, 640},
	//	{0, 437, 2551},
	//	{0, 542, 2551},
	//	{0, 647, 2551},
	//	{0, 737, 2551},
	//	{0, 807, 2551},
	//	{0, 875, 2520},
	//	{0, 893, 2440},
	//	{0, 876, 2340},
	//	{0, 788, 2307},
	//	{0, 715, 2306},
	//	{0, 138, 2313},
	//	{0, 78, 2287},
	//	{0, 57, 2198},
	//	{0, 81, 2104},
	//	{0, 144, 2069},
	//	{0, 239, 2069},
	//	{0, 339, 2069},
	//	{0, 965, 2048},
	//	{0, 1014, 2025},
	//	{0, 1123, 1974},
	//	{0, 1178, 1942},
	//	{0, 2565, 1948},
	//	{0, 2650, 1948},
	//	{0, 2715, 1948},
	//	{0, 2908, 1887},
	//	{0, 2983, 1887},
	//	{0, 3780, 1290},
	//	{0, 3675, 1290},
	//	{0, 3570, 1290},
	//	{0, 3483, 1283},
	//	{0, 3399, 1234},
	//	{0, 3315, 1201},
	//	{0, 3233, 1167},
	//	{0, 4467, 1149},
	//	{0, 4537, 1149},
	//	{0, 4612, 1149},
	//	{0, 4712, 1149},
	//	{0, 4807, 1149},
	//	{0, 4864, 1115},
	//	{0, 4879, 1034},
	//	{0, 4879, 964},
	//	{0, 4879, 899},
	//	{0, 4879, 739},
	//	{0, 5394, 721},
	//	{0, 5464, 721},
	//	{0, 5539, 721},
	//	{0, 5614, 721},
	//	{0, 5694, 721},
	//	{0, 5774, 721},
	//	{0, 5849, 721},
	//	{0, 5924, 721},
	//	{0, 6009, 721},
	//	{0, 6622, 726},
	//	{0, 6722, 726},
	//	{0, 6936, 727},
	//	{0, 6998, 702},
	//	{0, 7029, 617},
	//	{0, 7006, 519},
	//	{0, 6934, 493},
	//	{0, 6865, 519},
	//	{0, 6845, 607},
	//	{0, 6864, 700},
	//	{0, 7118, 726},
	//	{0, 7183, 726},
	//	{22, 813, 793},
	//	{29, 3345, 965},
	//	{30, 7397, 740},
	//	{25, 1417, 835},
	//	{19, 3240, 1920},
	//	{19, 3244, 2009},
	//	{19, 3245, 2103},
	//	{19, 3245, 2197},
	//	{19, 3370, 1725},
	//	{21, 3688, 1900},
	//	{19, 3245, 2284},
	//	{19, 3245, 2377},
	//	{19, 3245, 2457},
	//	{19, 3245, 2550},
	//	{19, 3246, 2643},
	//	{22, 3705, 2677},
	//	{0, 3062, 1886},
	//	{19, 3295, 1919},
	//	{19, 3267, 1921},
	//	{19, 3369, 1633},
	//	{19, 3072, 1620},
	//	{0, 3194, 1881},
	//	{0, 3292, 1856},
	//	{0, 3245, 1709},
	//	{0, 3173, 1744},
	//	{0, 3160, 1829},
	//	{0, 3318, 1797},
	//	{0, 3301, 1729},
	//	{0, 3248, 1880},
	//	{0, 3158, 1956},
	//	{0, 3157, 2043},
	//	{0, 3157, 2115},
	//	{0, 3157, 2205},
	//	{0, 3157, 2301},
	//	{0, 3157, 2391},
	//	{0, 3157, 2495},
	//	{0, 3157, 2577},
	//	{0, 3168, 2638},
	//	{0, 3212, 2684},
	//	{0, 3298, 2698},
	//	{0, 3344, 2698},
	//	{0, 3506, 2698},
	//	{0, 3559, 2673},
	//	{0, 3585, 2610},
	//	{0, 3565, 2538},
	//	{0, 3511, 2509},
	//	{0, 3442, 2535},
	//	{0, 3421, 2601},
	//	{0, 3448, 2674},
	//	{0, 3840, 1359},
	//	{0, 3840, 1535},
	//	{0, 3840, 1478},
	//	{0, 3841, 1417},
	//	{24, 2574, 924},
	//	{24, 2533, 923},
	//	{24, 2484, 923},
	//	{24, 3383, 2443},
	//	{24, 3431, 2443},
	//	{24, 3476, 2443},
	//	{24, 3524, 2443},
	//	{24, 3572, 2443},
	//	{24, 3621, 2443},
	//	{17, 3488, 2490},
	//	{21, 4015, 1671},
	//	{22, 478, 2543},
	//	{3, 3421, 1902},
	//	{19, 3370, 1819},
	//	{19, 3369, 1907},
	//	{0, 250, 2550},
	//	{0, 148, 2551},
	//	{20, 1557, 1872},
	//	{0, 2180, 2028},
	//	{0, 2180, 1951},
	//	{0, 2180, 1879},
	//	{0, 2180, 1791},
	//	{0, 384, 1696},
	//	{0, 384, 1736},
	//	{0, 384, 1776},
	//	{0, 384, 1816},
	//	{0, 344, 1696},
	//	{24, 304, 1696},
	//	{24, 264, 1696},
	//	{24, 224, 1696},
	//	{24, 184, 1696},
	//	{24, 144, 1696},
	//	{24, 104, 1696},
	//	{5, 26, 1713},
	//	{51, 693, 2157}
	//};

	Level::Level() {
		
	}

	Level::~Level() {

	}

	void Level::OnInit(int level) {

		/*int enemyData[][3];
		Enemy::getEnemiesData(&enemyData, level);*/

		//for (int i = 0; i < _; i++) {
		//	/*int id = ;
		//	int x = ;
		//	int y = ;*/

		//	switch (id) {
		//	case static_cast<int>(ENEMIES_LIST::BAMBOO) :
		//		enemies.push_back(new Bamboo(x, y, 0));
		//		break;

		//	case static_cast<int>(ENEMIES_LIST::CHEF) :
		//		enemies.push_back(new Chef(x, y, 0));
		//		break;

		//	case static_cast<int>(ENEMIES_LIST::EARTHWORM) :
		//		enemies.push_back(new Earthworm(x, y, 0));
		//		break;

		//	case static_cast<int>(ENEMIES_LIST::FLY) :
		//		enemies.push_back(new Fly(x, y, 0));
		//		break;

		//	}

		//}

		enemies.push_back(new Red(0, 0, 0));
		enemies.push_back(new Red(100, 0, 0));
		/*int bs = bricks.size();
		int is = items.size();
		

		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnInit();
		}

		for (int i = 0; i < is; i++) {
			items.at(i)->OnInit();
		}
		*/

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnInit();
		}

	}
	
	void Level::OnMove() {
		/*int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnMove();
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->OnMove();
		}*/

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnMove();
		}
	}

	void Level::OnShow() {
		/*int bs = bricks.size();
		for (int i = 0; i < bs; i++) {
			bricks.at(i)->OnShow();
		}

		int is = items.size();
		for (int i = 0; i < is; i++) {
			items.at(i)->OnShow();
		}*/

		int es = enemies.size();
		for (int i = 0; i < es; i++) {
			enemies.at(i)->OnShow();
			TRACE("Enemy: %d %d\n", enemies.at(i)->getTexture().Top(), enemies.at(i)->getTexture().Left());
		}
	}

}