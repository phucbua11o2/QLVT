1.	Quản lý nhập xuất vật tư: Ta tổ chức các danh sách sau:
- Danh sách Vattu : cây nhị phân tìm kiếm ( MAVT (C10), TENVT (C50), DVT (đơn vị tính), Số lượng tồn (số thực)). 
- Danh sách Nhanvien : danh sách tuyến tính là 1 mảng con trỏ    (MANV (int), HO, TEN, PHAI, Số CMND, con trỏ dshd): con trỏ dshd sẽ trỏ đến danh sách các hóa đơn mà nhân viên đó đã lập. Danh sách nhân viên có tối đa 500 nhân viên
- Danh sách HOADON : danh sách liên kết đơn(SoHD (C20), Ngày lập hóa đơn, Loai,  dscthd). Lọai chỉ nhận ‘N’ (phiếu nhập) hoặc ‘X’ (phiếu xuất), dscthd để lưu chi tiết các vật tư của hóa đơn đó.
- Danh sách CT_HOADON : danh sách tuyến tính ( MAVT, Soluong, Dongia, %VAT, trạng thái (1 : khách mua ; 0 – khách đã trả hàng). Một hóa đơn có tối đa 20 vật tư.

Chương trình có các chức năng sau: 
a/ Nhập vật tư : cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của vật tư; riêng số lượng tồn chỉ cho phép nhập khi đó là vật tư mới thêm.
b/ In danh sách vật tư tồn kho : liệt kê danh sách vật tư ra màn hình theo thứ tự mã vật tư giảm dần.  Kết xuất : Mã VT	Tên vật tư	Đơn vị tính	Số lượng tồn
c/ Nhập nhân viên: Cập nhập (thêm / xóa / hiệu chỉnh ) các nhân viên  dựa vào mã nhân viên, họ, tên, Số CMND không được rỗng. Phái chỉ nhận ‘Nam’, hoặc ‘Nu’ .
d/ In danh sách nhân viên theo thứ tự tên nhân viên tăng dần, nếu trùng tên thì tăng dần theo họ ra màn hình, 1 nhân viên / dòng
e/ Lập hóa đơn nhập/Lập hóa đơn xuất: nhập vào số hóa đơn, ngày lập, loại (chỉ nhận ký tự N hoặc X). Sau đó, tiếp tục cho phép nhập các vật tư của hóa đơn đó; Căn cứ vào loại hóa đơn, chương trình sẽ tự động cập nhật số lượng tồn. 
Lưu ý: - Nếu số lượng xuất không đủ hàng thì báo lỗi và in ra số lượng tồn hiện có trong 			kho;
- Chỉ được phép xóa vật tư đang lập của hóa đơn hiện tại. Khi hóa đơn đã ghi thì không được xóa các vật tư trong hóa đơn
f/ Trả hàng : user nhập vào số hóa đơn , chương trình sẽ liệt kê ra các vật tư trong hóa đơn để user chọn trả hàng. Lưu ý : chỉ cho trả hàng trong vòng 3 ngày tính từ ngày mua.
g/ In hóa đơn : In hóa đơn dựa vào số hóa đơn do ta nhập vào
h/ Liệt kê các hóa đơn do 1 nhân viên đã lập trong 1 khoảng thời gian: nhập vào mã nhân viên, 2 thời điểm từ ngày , đến ngày, chương trình sẽ in ra các hóa đơn mà nhân viên đã lập trong khoảng thời gian như trên. Kết xuất:
		BẢNG LIỆT KÊ CÁC HÓA ĐƠN TRONG KHOẢNG THỜI GIAN
			Từ ngày : ##/##/####   Đến ngày : ##/##/####
			Nhân viên : <họ tên nhân viên>
    Số HĐ	Ngày lập     Loại HĐ	 Mã VT    Tên VT   Số lượng  Đơn giá  Vat	Trị giá 
 i/ Thống kê doanh thu của cửa hàng trong từng tháng thuộc 1 năm do user nhập vào.
BẢNG THỐNG KÊ DOANH THU NĂM ####
 				THÁNG 		DOANH THU

Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập làm dữ liệu bị sai.

# QLVT
![image](https://user-images.githubusercontent.com/64189668/161422984-85d43ed3-9ecb-4d11-b636-a31909ec15b6.png)
