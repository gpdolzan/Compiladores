// program proc2 (input, output);
// var x, y: integer;
//    k: boolean;
//    procedure p(t:integer; var h: boolean);
//    var z:integer;
//    begin
//       if (t>1)
//       then y:=2
//       else y:=1;
//       z:= y;
//       y:=z*t;
//    end;
// begin
//    p(x, k)
// end.
program exemplo5 (input, output);
var n, k      : integer;
   f1, f2, f3 : integer;
begin
   read (n, k);
   f1:=0; f2:=1; k:=1;
   while k<=n do
   begin
      f3:=f1+f2;
      f1:=f2;
      f2:=f3;
      k:=k+1
   end;
   write (n, f1)
end.
