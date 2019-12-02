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

void themHoaDon(DSHoaDon &dshd, HoaDon hd) {
	if (dshd.SoLuong == Max) {
		cout << "Danh sach day." << endl;
		return;
	}

	int vitri;
	cout << "Nhap vi tri trong danh sach ma ban muon them hoa don: ";
	cin >> vitri;

	cout << "\n Hoa don da duoc them thanh cong"<<endl;

	if (vitri < 0 || vitri > dshd.SoLuong) 
	{
		cout << "Vi tri" << vitri << "khong hop le." << endl;
		return;
	}

	if (dshd.SoLuong > 0) {
		for (int i = dshd.SoLuong; i > vitri; i--) 
		{
			dshd.dshd[i] = dshd.dshd[i - 1];
		}
	}

	dshd.dshd[vitri] = hd;
	dshd.SoLuong += 1;
}

void xuatDSHoaDon(DSHoaDon dshd) {
	
	cout << "\nMa Hoa Don: "  "\t" "Ngay: "  "\t" "Thang: " << "\t" "Nam: " "\t" "Tong tien: " << endl;
	for (int i = 0; i < dshd.SoLuong; i++)
	{
		cout << endl;
		cout <<dshd.dshd[i].MaHD;
		cout << "\t\t" << dshd.dshd[i].NgayLap.Ngay;
		cout << "\t" << dshd.dshd[i].NgayLap.Thang;
		cout << "\t" << dshd.dshd[i].NgayLap.Nam;
		cout << "\t" << dshd.dshd[i].TongTien;
	}
		
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

int timTheoMaHD(DSHoaDon dshd , int x)
{
	int mahd;

	cout << "Nhap ma hoa don: "; 
	cin >> mahd;

	for (int i = 0; i < dshd.SoLuong; i++) {
		if (mahd == dshd.dshd[i].MaHD) {
			return i;
		}
	}

	return -1;
			
			
}
int timTheoNgayLap(DSHoaDon dshd) {
	NgayThangNam ntn;

	cout << "Nhap ngay: "; cin >> ntn.Ngay;
	cout << "Nhap thang: "; cin >> ntn.Thang;
	cout << "Nhap nam: "; cin >> ntn.Nam;

	for (int i = 0; i < dshd.SoLuong; i++) {
		if (ntn.Ngay == dshd.dshd[i].NgayLap.Ngay && ntn.Thang == dshd.dshd[i].NgayLap.Thang && ntn.Nam == dshd.dshd[i].NgayLap.Nam)
			return i;
	}

	return -1;
}
void xoaTheoMaHD(DSHoaDon &dshd) {
	int vitri = timTheoMaHD(dshd);

	if (vitri != -1) {
		for (int i = vitri; i < dshd.SoLuong - 1; i++)
			dshd.dshd[i] = dshd.dshd[i + 1];

		dshd.SoLuong -= 1;
		cout << "Xoa thanh cong" << endl;
	}
	else{
		cout << "Khong tim thay." << endl;
	}
}
void xoaTheoNgayLap(DSHoaDon &dshd) {
	int vitri = timTheoNgayLap(dshd);

	if (vitri != -1) {
		for (int i = vitri; i < dshd.SoLuong - 1; i++)
			dshd.dshd[i] = dshd.dshd[i + 1];

		dshd.SoLuong -= 1;
		cout << "Xoa thanh cong" << endl;
	}
	else{
		cout << "Khong tim thay." << endl;
	}
}

