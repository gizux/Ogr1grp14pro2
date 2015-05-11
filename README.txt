ÖDEV 2

Mehmet Eray ALAKESE, Gizem ULUTAÞ
G111210087  B101210033

Shared Memory Yazma-Okuma
1. Giriş

Bu program farklı çalıştırılabilir dosyalardan aynı paylaşımlı belleğe veri yazma 
ve okuma işlemlerinin nasıl gerçekleştiğinin anlaşılması için yazılmıştır.

Program çalıştığında paylaşımlı bellekten yer ayrılır. Daha sonra fork sistem çağrısıyla
yavru proses ve ebeveyn proses oluşturulur. Yavru proseste ayrı bir dosya olarak 
kodlanmış Sampler execlp() sistem çağrısıyla çağırılıp, paylaşımlı bellek id’si 
parametre olarak gönderilmesi istenmiştir. Sampler parametre olarak aldığı paylaşımlı 
bellek id’si ile paylaşımlı belleğe bağlanır (shmat() ile) ve 0dan başlayıp her 
seferinde artan record number ile 0-99 aralığında ürettiği rastgele (rand() ile) 
sayıyı paylaşımlı belleğe saniyede bir yazar.

Bu sırada ebeveyn prosesin devamı olan Collector, Sampler’ın yazdığı verileri 
paylaşımlı belleğe okuma modunda bağlanarak okur ve ekrana yazdırması amaçlanmıştır.

ctrl + c komutuyla programdan çıkılır.

2. Dosyalar

- Readme   : 		Þu anda okumakta olduğunuz dosya
- Main.c      :		Kaynak program dosyası 
- Sampler.c :		Paylaşımlı belleğe veri yazan proses dosyası
- Makefile :		Derleme dosyası

3. Derleme

Konsoldan ilgili dizine gidilir, kabuk açılır ve "make" komutu yazılır. 
Derleme işlemi otomatik olarak yapılacaktır.

4. Çalıştırma

Derleme için yazılan make komutu programın çalıştırılması için yeterlidir.

5. Hatalar ve Eksiklikler

execlp fonksiyonunun kullanımından kaynaklanan bir hatadan dolayı Sampler 
prosesi main’de ayrı bir fonksiyon olarak tasarlanmış ve fork() sonucu oluşan 
çocuk proseste çağrılarak istenen işlem gerçekleştirilmiştir. 
Ayrıca execlp() fonksiyonu da yorum satırı olarak dosyada bırakılmıştır. 
