.\render\cpdf.exe -bottom 40 -font "Courier-Bold" -add-text "-- %%Page / %%EndPage --" .\statement.pdf -o .\statement.pdf
.\render\cpdf.exe -merge .\head.pdf .\info.pdf .\statement.pdf -o .\contest.pdf
