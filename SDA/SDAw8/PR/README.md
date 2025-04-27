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
- doubly linked list
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


