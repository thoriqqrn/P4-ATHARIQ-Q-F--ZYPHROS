# P4-ATHARIQ-Q-F--ZYPHROS

Membuat dua objek PersegiPanjang (p1 dan p2).
Menggabungkan p1 dan p2 menjadi p3 dan mencetak hasilnya.
Mengambil irisan dari p1 dan p2 menjadi p4 dan mencetak hasilnya.
Menggandakan luas p1 dan mencetak hasilnya.
Mengurangi luas p2 menjadi setengahnya dan mencetak hasilnya.
Memeriksa apakah p1 dan p2 beririsan dan mencetak hasilnya.

PersegiPanjang operator+(const PersegiPanjang &other)
Menggabungkan dua persegi panjang yang beririsan dan mengembalikan persegi panjang baru yang mencakup area gabungan dari kedua persegi panjang tersebut.

PersegiPanjang operator-(const PersegiPanjang &other)
Mengambil irisan dari dua persegi panjang yang beririsan dan mengembalikan persegi panjang baru yang merupakan irisan dari kedua persegi panjang tersebut.

PersegiPanjang &operator++()
Menggandakan luas dari persegi panjang dengan mengalikan panjang dan lebar dengan sqrt(2).

PersegiPanjang &operator--()
Mengurangi luas dari persegi panjang menjadi setengahnya dengan membagi panjang dan lebar dengan sqrt(2).

void cetak() const
Mencetak koordinat batas persegi panjang (xmin, ymin, xmax, ymax) ke konsol.

bool operator==(const PersegiPanjang &other) const
Memeriksa apakah dua persegi panjang saling beririsan. Mengembalikan true jika beririsan dan false jika tidak.
