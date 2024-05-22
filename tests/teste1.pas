program exemplo74 (input, output);
var z, x: integer;
   procedure p;
   var y : integer;
   begin
      write(z)
   end;


   procedure g(t:integer);
   var y : integer;
   begin
      y:=t*t; z:=z+x+y;
      write(z)
   end;

   function cunf: integer;
   var y : integer;
   begin
      cunf := 10; 
   end;

   function func(t:integer): integer;
   var y : integer;
   begin
      func := t*t; 
      z:=z+x+y;
      write(z)
   end;

   procedure h (y : integer);
   var x : integer;
      procedure f(y : integer);
      var t : integer;
      begin
         t:=z+x+y; g(t);
         z:=t
      end;
   begin
      x:=y+1;
      f(x);
      g(z+x)
   end;
begin
   p;
   p();
   cunf;
   cunf();
   g(x);
   func(cunf());
   x := cunf();
end.