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

void xuLy(HoaDon &hd, DSHoaDon &dshd, int chon) {
	int vitri;

	switch (chon)
	{
	case 1:
		nhapHoaDon(hd);
		themHoaDon(dshd, hd);
		break;
	case 2:
		xuatDSHoaDon(dshd);
		break;
	case 3:
		vitri = timTheoMaHD(dshd);
		if (vitri != -1) {
			cout << dshd.dshd[vitri].MaHD << "\t" << dshd.dshd[vitri].NgayLap.Ngay << "\t" << dshd.dshd[vitri].NgayLap.Thang << "\t" << dshd.dshd[vitri].NgayLap.Nam << "\t" << dshd.dshd[vitri].TongTien << endl;
		}
		else
			cout << "Khong tim thay." << endl;
		break;
	case 4:
		vitri = timTheoNgayLap(dshd);
		if (vitri != -1) {

			cout << dshd.dshd[vitri].MaHD << "\t" << dshd.dshd[vitri].NgayLap.Ngay << "\t" << dshd.dshd[vitri].NgayLap.Thang << "\t" << dshd.dshd[vitri].NgayLap.Nam << "\t" << dshd.dshd[vitri].TongTien << endl;
		}
		else
			cout << "Khong tim thay." << endl;
		break;
	case 5:
		xoaTheoMaHD(dshd);
		break;
	case 6:
		xoaTheoNgayLap(dshd);
		break;
	case 7:
		sapXepTheoMaHDTangDan(dshd);
		break;
	case 8:
		sapXepTheoTongTienTangDan(dshd);
		break;
	case 9:
		tinhTongtien(hd, dshd);
		cout << "Tong tien trong danh sach:" << tinhTongtien(hd, dshd) << endl;
		break;
	default:
		cout << "\n So ban nhap khong hop le" << endl;;
		
	}
}
