#pragma once
#include"DoublyCircularLinkedList.cpp"
#include"Pair.cpp"
#include"List.cpp"
#include"order.h"
#include"foods.h"
#include"drinks.h"
#include"Bill.h"
#include"BillTaiCho.h"
#include"BillOnline.h"
#include"NhanVien.h"

template class List<NhanVien*>;
template class List<Bill*>;
template class Pair<order, int>;
template class DoublyCircularLinkedList<Pair<order, int>>;
template class DoublyCircularLinkedList<order>;
template class List<foods>;
template class List<drinks>;
template class List<string>;