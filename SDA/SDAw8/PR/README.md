# studi kasus soal ets semester 2
### tentang & tujuan
program manajemen perpustakaan yang diharapkan dapat memenuhi serta menggunakan 3 metode/skenario dalam struktur nya   ↓← →↑

- Singly linked list
    <pre>
    [buku1|stok|* ]→ ... →[bukuN|stok|*]→NULL
       ↑                     ↑
    [  *  ]               [  *  ]
    [-----]               [-----]
    [prior]               [prior]
    [-----]               [-----]
    [nama1]               [nama1]
       ↑                     ↑
      ...                   ...
       ↑                     ↑
    [  *  ]               [  *  ]
    [-----]               [-----]
    [prior]               [prior]
    [-----]               [-----]
    [namaN]               [namaN]
    </pre>
- double pointer linked list
    <pre>
      [* |buku1|stok|*]→ ... →[* |bukuN|stok|*]→NULL
       ↓                       ↓
    [nama1]                 [nama1]
    [-----]                 [-----]
    [prior]                 [prior]
    [-----]                 [-----]
    [  *  ]                 [  *  ]
       ↓                       ↓
      ...                     ...
       ↓                       ↓
    [namaN]                 [namaN]
    [-----]                 [-----]
    [prior]                 [prior]
    [-----]                 [-----]
    [  *  ]                 [  *  ]
       ↓                       ↓
      NULL                    NULL
    </pre>
- array
    <pre>
    [buku1][stok][*]→ [nama1|prior|*]→ ... →[namaN|prior|*]→NULL
    [buku2][stok][*]→ [nama1|prior|*]→ ... →[namaN|prior|*]→NULL
    [...]           → [nama1|prior|*]→ ... →[namaN|prior|*]→NULL
    [bukuN][stok][*]→ [nama1|prior|*]→ ... →[namaN|prior|*]→NULL
    </pre>

### hasil dan kendala
hasil belum ada karena program belum selesai<br>

@2025-04-27T13:27:30

update per hari ini<br>
program belum dapat sesuai dengan harapan<br>
program ini juga tidak sepenuhnya buatan saya<br>
karena akan segera habis saya commit apa adanya<br>
@2025-05-01T23:51:30

