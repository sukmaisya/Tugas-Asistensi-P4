# Tugas-Asistensi-P4
Program berisi tentang simulasi Pet Cafe  


Program ini adalah program simulasi Pet Cafe yang mengelola interaksi antara karakter manusia dan hewan peliharaan di sebuah kafe hewan peliharaan. Menggunakan struktur data untuk menyimpan informasi tentang manusia dan hewan peliharaan, program memungkinkan pengguna untuk menambahkan karakter, melakukan aksi seperti mengelus hewan peliharaan yang meningkatkan jumlah loves hewan, memberikan bantuan kepada manusia yang juga meningkatkan loves mereka, serta menampilkan atribut karakter. Selain itu, player dapat melihat dan mengurutkan hewan peliharaan berdasarkan jumlah loves mereka. Program beroperasi dalam loop interaktif, menerima perintah dari player hingga mereka memilih untuk keluar dengan mengetik "exit", di mana program akan menampilkan pesan penutup. Program terdiri dari diantaranya:

Struktur Data
1. Human: Struktur data ini menyimpan informasi tentang manusia, termasuk:
   - name: Nama manusia.
   - energy: Energi manusia (dalam bentuk integer).
   - loves: Jumlah cinta yang dimiliki manusia (juga dalam bentuk integer).
   - type: Tipe hewan peliharaan yang dimiliki (meskipun tidak digunakan dalam bagian ini).

2. Pet: Struktur data ini menyimpan informasi tentang hewan peliharaan, dengan atribut yang sama seperti struktur `Human`, yaitu:
   - name: Nama hewan peliharaan.
   - energy: Energi hewan peliharaan.
   - loves: Jumlah cinta yang dimiliki hewan peliharaan.
   - type: Tipe hewan peliharaan (misalnya, "Cat").
     
Fungsi Utama
1. searchCharacter: Fungsi ini mencari baik manusia maupun hewan peliharaan berdasarkan nama. Jika ditemukan, fungsi ini mengembalikan pointer ke karakter tersebut; jika tidak, mengembalikan NULL.
2. petting: Fungsi ini meningkatkan jumlah cinta (loves) dari hewan peliharaan ketika pengguna melakukan aksi "petting" (mengelus). Jika hewan peliharaan ditemukan, maka nilai loves akan bertambah 10.
3. help: Fungsi ini memberikan bantuan kepada manusia dan meningkatkan jumlah cinta mereka sebanyak 5.
4. showAttributes: Fungsi ini menampilkan atribut energi dan cinta dari karakter (baik manusia maupun hewan peliharaan) berdasarkan nama yang diberikan.
5. showSortedPetsByLoves: Fungsi ini menampilkan dan mengurutkan hewan peliharaan berdasarkan jumlah cinta (`loves`) mereka. Pengguna dapat memilih untuk melihat hewan peliharaan berdasarkan tipe tertentu (misalnya, "Cat").
6. addHuman dan addPet: Fungsi-fungsi ini digunakan untuk menambahkan manusia dan hewan peliharaan ke dalam array yang menyimpan data mereka.

Alur Program
1. Program dimulai dengan menambahkan beberapa manusia dan hewan peliharaan dengan menggunakan fungsi `addHuman` dan `addPet`.
2. Setelah itu, program memasuki loop interaktif di mana pengguna dapat memasukkan perintah:
   - petting [nama_hewan]: Untuk mengelus hewan peliharaan.
   - attr [nama_karakter]: Untuk menampilkan atribut karakter.
   - help [nama_manusia]: Untuk memberikan bantuan kepada manusia.
   - show cat loves: Untuk menampilkan dan mengurutkan hewan peliharaan tipe "Cat" berdasarkan jumlah cinta mereka.
3. Program terus berjalan hingga pengguna mengetik "exit", yang akan menghentikan program.


Kemudian, input dan output yang dihasilkan dari program adalah sebagai berikut:
Output Awal
Saat program dijalankan, output awal yang muncul adalah:
Welcome to our Pet Cafe!
Enter commands (type 'exit' to quit):
Ini memberi tahu pengguna bahwa mereka telah memasuki kafe hewan peliharaan dan dapat mulai memasukkan perintah.

Output Berdasarkan Perintah
Setelah itu, pengguna dapat memasukkan berbagai perintah. Berikut adalah beberapa contoh output yang mungkin dihasilkan berdasarkan perintah yang dimasukkan:
1. Perintah 'petting [nama_hewan]'
Jika pengguna mengetik perintah seperti `petting pou`, outputnya akan menjadi:
You are gaining the pet's loves!
Jika nama hewan peliharaan tidak ditemukan, outputnya akan menjadi:
Pet not found!

2. Perintah attr [nama_karakter]

Jika pengguna mengetik perintah seperti 'attr aisyah', outputnya akan menampilkan atribut karakter tersebut:
aisyah's Energy is 60
aisyah's Loves is 80
Jika nama karakter tidak ditemukan, outputnya akan menjadi:
Character not found!

3. Perintah help [nama_manusia]
Jika pengguna mengetik perintah seperti 'help selma', outputnya akan menunjukkan bahwa manusia tersebut menerima bantuan dan mencetak jumlah cinta yang baru:
selma received help! Loves is now: 75
Jika nama manusia tidak ditemukan, outputnya akan menjadi:
Human not found!

4. Perintah show cat loves
Jika pengguna mengetik perintah ini, program akan menampilkan daftar hewan peliharaan tipe "Cat" yang diurutkan berdasarkan jumlah cinta mereka. Contoh outputnya bisa seperti ini:
Sorted Cat by loves:
nou: Loves = 60
pou: Loves = 50
mou: Loves = 55
sou: Loves = 25

5. Perintah Tidak Dikenal
Jika pengguna memasukkan perintah yang tidak dikenali, seperti `random command`, outputnya akan menjadi:
Unknown command!

6. Mengakhiri Program
Ketika pengguna mengetik 'exit', program akan mengeluarkan pesan penutup:
Thank you for your visit!

Sekian penjelasan tentang program Pet Cafe. Hope you have wonderful dayy...
