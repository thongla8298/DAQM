#include "Header.h";

void nhapHoaDon(HoaDon &hd) {
	cout << endl;
	cout << "Nhap MaHD: "; cin >> hd.MaHD;
	cout << "Nhap Ngay: "; cin >> hd.NgayLap.Ngay;
	cout << "Nhap Thang: "; cin >> hd.NgayLap.Thang;
	cout << "Nhap Nam: "; cin >> hd.NgayLap.Nam;
	cout << "Nhap Tong Tien: "; cin >> hd.TongTien;
}

void menu() {
	cout << endl;
	cout << "1. Them mot hoa don vao vi tri bat ki." << endl;
	cout << "2. Xuat danh sach hoa don." << endl;
	cout << "3. Tim kiem theo ma hoa don" << endl;
	cout << "4. Tim kiem theo ngay lap" << endl;
	cout << "5. Xoa theo ma hoa don" << endl;
	cout << "6. Xoa theo ngay lap" << endl;
	cout << "7. Sap xep theo ma hoa don tang dan." << endl;
	cout << "8. Sap xep theo tong tien tang dan." << endl;
	cout << "9. Tinh tong tien" << endl;
	cout << "Nhan -99 de thoat." << endl;
}

void doiCho(HoaDon &a, HoaDon &b) {
	HoaDon tam = a;
	a = b;
	b = tam;
}

void sapXepTheoMaHDTangDan(DSHoaDon dshd) {
	for (int i = 0; i < dshd.SoLuong - 1; i++) {
		for (int j = i + 1; j < dshd.SoLuong; j++) {
			if (dshd.dshd[i].MaHD > dshd.dshd[j].MaHD)
				doiCho(dshd.dshd[i], dshd.dshd[j]);
		}
	}

	xuatDSHoaDon(dshd);
}

void sapXepTheoTongTienTangDan(DSHoaDon dshd) {
	for (int i = 0; i < dshd.SoLuong - 1; i++) {
		for (int j = i + 1; j <= dshd.SoLuong; j++) {
			if (dshd.dshd[i].TongTien > dshd.dshd[j].TongTien)
				doiCho(dshd.dshd[i], dshd.dshd[j]);
		}
	}

	xuatDSHoaDon(dshd);
}

void luaChon(HoaDon &hd, DSHoaDon &dshd) {
	int chon;
	do {
		menu();
		cout << "Moi ban chon: "; cin >> chon;
		xuLy(hd, dshd, chon);
	} while (chon != -99)
}   

int tinhTongtien(HoaDon hd, DSHoaDon dshd)
{
	int tong = 0;
	for (int i = 0; i < dshd.SoLuong; i++){
		
		{

			tong = tong - dshd.dshd[i].TongTien;
		}
	}
	return tong;
}