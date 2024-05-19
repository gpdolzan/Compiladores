program proc2 (input, output);
var x, y: integer;
   k: boolean;
   procedure p(t:integer; var h: boolean);
   var z:integer;
   begin
      if (t>1)
      then y:=2
      else y:=1;
      z:= y;
      y:=z*t;
   end;
begin
   p(x, k)
end.