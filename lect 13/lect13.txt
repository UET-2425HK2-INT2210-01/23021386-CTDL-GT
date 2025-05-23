1.
- <an xml tag> : khớp, có ký tự giữa < và >, không có > ở giữa.
- <opentag> <closetag> : không khớp toàn bộ chuỗi: Regex chỉ khớp đến dấu > đầu tiên, phần sau là một thẻ khác.
- </closetag> : khớp: < + /closetag + > → hợp lệ.
- <> : không khớp: không có ký tự nào giữa < và >
- <with attribute="77"> : khớp: tất cả các ký tự giữa < và > đều không phải >.

2.
- abc: Khớp: a + b + c
- abbbbbbbb: Khớp: a + b + nhiều b
- azc: Không khớp: z không khớp [bc]
- abcbcbcbc: Khớp: a + b + c, lặp [bc]
- ac: Không khớp: thiếu ký tự sau a, không có ký tự đứng giữa a và [bc]+
- azcbbbbcbccc: Không khớp: z không phải [bc], nên không khớp toàn chuỗi (hoặc không khớp từ đầu a)

3.
- very fat man: Không khớp, thiếu "tall" hoặc "ugly" sau "fat"
- fat tall man: Không khớp, thiếu "very"
- very very fat ugly man: Khớp, "very" x2 + "fat" + "ugly" + "man"
- very very very tall man: Khớp, "very" x3 + "tall" + "man"

4.
regex: ^.{3}\..{3}\..{3}\..{3}$
 - \.: kí tự .
 - .{3}: 11 kí tự bất kì lặp lại 3 lần

5.
- (123) 456 7899: Khớp: có dấu ngoặc, dấu cách
- (123).456.7899: Khớp: dấu chấm ngăn cách
- (123)-456-7899: Khớp: dấu gạch ngang
- 123-456-7899: Khớp: không có dấu ngoặc, dùng gạch ngang
- 123 456 7899: Khớp: dùng dấu cách
- 1234567899: Khớp: không có dấu phân cách nào

6.
/^[a-zA-Z0-9]+(?:[-_ ][a-zA-Z0-9]+)*$/
