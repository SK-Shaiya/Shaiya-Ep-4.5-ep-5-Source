#include "pch.h"
//https://github.com/SK-Shaiya
//if you get stuck :D just add me   [s.k#8903]

//expressions
int icon_render = 0x4A3400;
int over_render = 0x4A2690;
int bag_retn = 0x4F689C;
int bag_jump = 0x4F68B2;
int bar_retn = 0x4E039A;
int bar_jump = 0x4E03A7;
//arrays for storing item ids
std::array<int, 2048> bag_arr;
std::array<int, 1024> bar_arr;
//array that contains fire items
std::array<int, 512> fire_arr = { 1092,1102,1112,2092,2102,2112,2204,3092,3102,3112,4092,4102,4112,4202,5097,5107,5117,5127,5137,5147,6097,6107,6117,6127,6137,6147,
	7097,7107,7117,7127,7137,7147,7202,7207,8097,8107,8117,8127,8137,8147,9092,9102,9112,9122,9132,9142,9211,10092,10102,10112,10122,10132,10142,11192,11102,11112,
	11201,12107,12117,12127,12137,12147,12157,12205,12208,12216,12219,13097,13107,13117,13127,13137,13147,13206,14092,14102,14112,15092,15102,15112,15122,15132,15142,
	15202 };
//array that contains water items
std::array<int, 512> water_arr = { 1093,1103,1113,2093,2103,2113,2202,3093,3103,3113,4093,4103,4113,4205,5098,5108,5118,5128,5138,5148,6098,6108,6118,6128,6138,6148,
	7098,7108,7118,7128,7138,7148,7203,7210,8098,8108,8118,8128,8138,8148,9093,9103,9113,9123,9133,9143,9202,10093,10103,10113,10123,10133,10143,11093,11103,11113,
	11204,12108,12118,12128,12138,12148,12158,12206,12207,12222,12225,13098,13108,13118,13128,13138,13148,13203,14093,14103,14113,15093,15103,15113,15123,15133,15143,
	15212 };
//array that contains earth items
std::array<int, 512> earth_arr = { 1094,1104,1114,2094,2104,2114,2206,3094,3104,3114,4094,4104,4114,4207,5099,5109,5119,5129,5139,5149,6099,6109,6119,6129,6139,6149,
	7099,7109,7119,7129,7139,7149,7209,7212,8099,8109,8119,8129,8139,8149,9094,9104,9114,9124,9134,9144,9213,10094,10104,10114,10124,10134,10144,11094,11104,11114,
	11206,12109,12119,12129,12139,12149,12159,12218,12221,12224,12227,13099,13109,13119,13129,13139,13149,13208,14094,14104,14114,15094,15104,15114,15124,15134,15144,
	15214 };
//array that contains wind items
std::array<int, 512> wind_arr = { 1095,1105,1115,2095,2105,2115,2205,3095,3105,3115,4095,4105,4115,4206,5100,5110,5120,5130,5140,5150,6100,6110,6120,6130,6140,6150,
	7100,7110,7120,7130,7140,7150,7208,7211,8100,8110,8120,8130,8140,8150,9095,9105,9115,9125,9135,9145,9212,10095,10105,10115,10125,10135,10145,11095,11105,11115,
	11205,12110,12120,12130,12140,12150,12160,12217,12220,12223,12226,13100,13110,13120,13130,13140,13150,13207,14095,14105,14115,15095,15105,15115,15125,15135,15145,
	15213 };


//finds fire items
bool fire_res(int val) {
	auto res = std::find(std::begin(fire_arr), std::end(fire_arr), val);
	if (res != std::end(fire_arr)) {
		return true;
	}
	else {
		return false;
	}
}

//finds water items
bool water_res(int val) {
	auto res = std::find(std::begin(water_arr), std::end(water_arr), val);
	if (res != std::end(water_arr)) {
		return true;
	}
	else {
		return false;
	}
}

//finds earth items
bool earth_res(int val) {
	auto res = std::find(std::begin(earth_arr), std::end(earth_arr), val);
	if (res != std::end(earth_arr)) {
		return true;
	}
	else {
		return false;
	}
}

//finds wind items
bool wind_res(int val) {
	auto res = std::find(std::begin(wind_arr), std::end(wind_arr), val);
	if (res != std::end(wind_arr)) {
		return true;
	}
	else {
		return false;
	}
}

//hooks bag items
void __declspec(naked) bag_hook() {
	__asm {
		pushad
		//first slot
		mov dl, byte ptr[eax + 0x8666E2]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//second slot
		mov dl, byte ptr[eax + 0x8666E3]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//third slot
		mov dl, byte ptr[eax + 0x8666E4]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//fourth slot
		mov dl, byte ptr[eax + 0x8666E5]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//fifth slot
		mov dl, byte ptr[eax + 0x8666E6]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//sixth slot
		mov dl, byte ptr[eax + 0x8666E7]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//move all the types into ecx
		movzx ecx, byte ptr[eax + 0x8666DD]
		//multiply the types by 1000
		imul ecx, 0x3E8
		//move all the type ids into edx
		movzx edx, byte ptr[eax + 0x8666DE]
		//add the type ids to the types
		add ecx, edx
		//store the item ids in an array
		mov[eax + bag_arr], ecx
		//save the item id array in ebx
		mov ebx, [eax + bag_arr]
		push ebx
		call fire_res
		add esp, 0x4
		test al, al
		jne _fire
		push ebx
		call water_res
		add esp, 0x4
		test al, al
		jne _water
		push ebx
		call earth_res
		add esp, 0x4
		test al, al
		jne _earth
		push ebx
		call wind_res
		add esp, 0x4
		test al, al
		jne _wind
		popad
		//original code
		mov eax, dword ptr ss : [esp + 0x10]
		push 0x1
		jmp bag_retn

		_fire : //red
		popad
			mov eax, dword ptr ss : [esp + 0x10]
			push 0x1
			push 0x0
			lea ebp, dword ptr ds : [edi + 0x2C]
			push edx
			mov edx, dword ptr ss : [esp + 0x20]
			push ebx
			push esi
			push eax
			push edx
			push ecx
			mov ecx, ebp
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x10]
			mov esi, dword ptr ss : [esp + 0x14]
			push 0x20 //icon size
			push 0x20 //icon size
			push ecx //position
			push esi //position
			push 0x50FF0000 //overlay color
			call over_render
			add esp, 0x14
			jmp bag_jump

			_water : //blue
		popad
			mov eax, dword ptr ss : [esp + 0x10]
			push 0x1
			push 0x0
			lea ebp, dword ptr ds : [edi + 0x2C]
			push edx
			mov edx, dword ptr ss : [esp + 0x20]
			push ebx
			push esi
			push eax
			push edx
			push ecx
			mov ecx, ebp
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x10]
			mov esi, dword ptr ss : [esp + 0x14]
			push 0x20
			push 0x20
			push ecx
			push esi
			push 0x5000FFFF
			call over_render
			add esp, 0x14
			jmp bag_jump

			_earth : //green
		popad
			mov eax, dword ptr ss : [esp + 0x10]
			push 0x1
			push 0x0
			lea ebp, dword ptr ds : [edi + 0x2C]
			push edx
			mov edx, dword ptr ss : [esp + 0x20]
			push ebx
			push esi
			push eax
			push edx
			push ecx
			mov ecx, ebp
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x10]
			mov esi, dword ptr ss : [esp + 0x14]
			push 0x20
			push 0x20
			push ecx
			push esi
			push 0x5000FF00
			call over_render
			add esp, 0x14
			jmp bag_jump

			_wind : //white
		popad
			mov eax, dword ptr ss : [esp + 0x10]
			push 0x1
			push 0x0
			lea ebp, dword ptr ds : [edi + 0x2C]
			push edx
			mov edx, dword ptr ss : [esp + 0x20]
			push ebx
			push esi
			push eax
			push edx
			push ecx
			mov ecx, ebp
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x10]
			mov esi, dword ptr ss : [esp + 0x14]
			push 0x20
			push 0x20
			push ecx
			push esi
			push 0x50FFFFFF
			call over_render
			add esp, 0x14
			jmp bag_jump
	}
}

//hooks skill bar items
void __declspec(naked) bar_hook() {
	__asm {
		pushad
		//first slot
		mov dl, byte ptr[esi + 0x8666E2]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//second slot
		mov dl, byte ptr[esi + 0x8666E3]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//third slot
		mov dl, byte ptr[esi + 0x8666E4]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//fourth slot
		mov dl, byte ptr[esi + 0x8666E5]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//fifth slot
		mov dl, byte ptr[esi + 0x8666E6]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//sixth slot
		mov dl, byte ptr[esi + 0x8666E7]
		cmp dl, 0x43 //blaze-burn lv1
		je _fire
		cmp dl, 0x92 //blaze-light lv1
		je _fire
		cmp dl, 0xB5 //blaze-burn lv2
		je _fire
		cmp dl, 0xB9 //blaze-light lv2
		je _fire
		cmp dl, 0xB1 //phoenix
		je _fire
		cmp dl, 0x44 //water-fear lv1
		je _water
		cmp dl, 0x93 //water-light lv1
		je _water
		cmp dl, 0xB6 //water-fear lv2
		je _water
		cmp dl, 0xBA //water-light lv2
		je _water
		cmp dl, 0xB2 //hydra
		je _water
		cmp dl, 0x45 //earth-shock lv1
		je _earth
		cmp dl, 0x94 //earth-panic lv1
		je _earth
		cmp dl, 0xB7 //earth-shock lv2
		je _earth
		cmp dl, 0xBB //earth-panic lv2
		je _earth
		cmp dl, 0xB3 //terra
		je _earth
		cmp dl, 0x46 //wind-gale lv1
		je _wind
		cmp dl, 0x95 //wind-scroll lv1
		je _wind
		cmp dl, 0xB8 //wind-gale lv2
		je _wind
		cmp dl, 0xBC //wind-scroll lv2
		je _wind
		cmp dl, 0xB4 //storm
		je _wind
		//move all the types into ecx
		movzx ecx, byte ptr[esi + 0x8666DD]
		//multiply the types by 1000
		imul ecx, 0x3E8
		//move all the type ids into edx
		movzx edx, byte ptr[esi + 0x8666DE]
		//add the type ids to the types
		add ecx, edx
		//store the item ids in an array
		mov[esi + bar_arr], ecx
		//save the item id array in ebx
		mov ebx, [esi + bar_arr]
		push ebx
		call fire_res
		add esp, 0x4
		test al, al
		jne _fire
		push ebx
		call water_res
		add esp, 0x4
		test al, al
		jne _water
		push ebx
		call earth_res
		add esp, 0x4
		test al, al
		jne _earth
		push ebx
		call wind_res
		add esp, 0x4
		test al, al
		jne _wind
		popad
		//original code
		push 0x0
		push edx
		push ebx
		push edi
		jmp bar_retn

		_fire : //red
		popad
			push 0x0
			push edx
			push ebx
			push edi
			push eax
			push ecx
			mov ecx, dword ptr ss : [esp + 0x2C]
			push - 0x1
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x18]
			mov eax, dword ptr ss : [esp + 0x1C]
			push 0x20 //icon size
			push 0x20 //icon size
			push ecx //position
			push eax //position
			push 0x50FF0000 //overlay color
			call over_render
			add esp, 0x14
			jmp bar_jump

			_water : //blue
		popad
			push 0x0
			push edx
			push ebx
			push edi
			push eax
			push ecx
			mov ecx, dword ptr ss : [esp + 0x2C]
			push - 0x1
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x18]
			mov eax, dword ptr ss : [esp + 0x1C]
			push 0x20
			push 0x20
			push ecx
			push eax
			push 0x5000FFFF
			call over_render
			add esp, 0x14
			jmp bar_jump

			_earth : //green
		popad
			push 0x0
			push edx
			push ebx
			push edi
			push eax
			push ecx
			mov ecx, dword ptr ss : [esp + 0x2C]
			push - 0x1
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x18]
			mov eax, dword ptr ss : [esp + 0x1C]
			push 0x20
			push 0x20
			push ecx
			push eax
			push 0x5000FF00
			call over_render
			add esp, 0x14
			jmp bar_jump

			_wind : //white
		popad
			push 0x0
			push edx
			push ebx
			push edi
			push eax
			push ecx
			mov ecx, dword ptr ss : [esp + 0x2C]
			push - 0x1
			call icon_render
			mov ecx, dword ptr ss : [esp + 0x18]
			mov eax, dword ptr ss : [esp + 0x1C]
			push 0x20
			push 0x20
			push ecx
			push eax
			push 0x50FFFFFF
			call over_render
			add esp, 0x14
			jmp bar_jump
	}
}

//main function
void Init() {
	Hook((void*)0x4F6896, bag_hook, 6);
	Hook((void*)0x4E0395, bar_hook, 5);
}
