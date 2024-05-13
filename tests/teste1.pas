program proc2 (input, output);
var x, y: integer;
   procedure p(t:integer);
   var z:integer;
   begin
      if (t>1)
      then y:=2
      else y:=1;
      z:= y;
      y:=z*t;
   end;
begin
   x := x + y;
end.