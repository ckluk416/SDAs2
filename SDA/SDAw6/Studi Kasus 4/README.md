# Program Cek Riwayat Website
program ini merupakan impelemntasi dari NRLL, stack, dan queue.
## disclaimer
program ini masih belum sepenuhnya sukses sesuai ekspektasi, jika dijalankan masih ada kendala khususnya ketika memprint list daftar website, karena inputan website dari user dimasukkan kedalam dua list yang berbeda, contoh:
| stack         | queue         |
| ------------- | ------------- |
| kembang.com  | sayang.com    |
| ikhlas.com  | ikhlas.com    |
| sayang.com  | kembang.com    |

saat memprint list (opsi 2 dalam program) akan:
| opsi 2         | 
| ------------- | 
| kembang.com  | 
| ikhlas.com  | 
| sayang.com  | 

<br><br>

ketika memilih opsi 4 (menghapus riwayat terlama)
| stack         | queue         |
| ------------- | ------------- |
| kembang.com  | sayang.com    |
| ikhlas.com  | ikhlas.com    |
| sayang.com  |   |

namun karena elemen masih ada di list lain maka tampilan akan tetap:
| opsi 2         | 
| ------------- | 
| kembang.com  | 
| ikhlas.com  | 
| sayang.com  | 

<br>

@2025-03-23T23:12:30
