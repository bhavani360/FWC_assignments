module helloworldfpga(

    input  wire X,
    input  wire Y,
    input  wire Z,
    
    output wire F,
    );
     assign X=1;
     assign Y=0;
     assign Z=0;
    
    always @(*)
    begin
   F=((X&Y)|(Y&Z)); 
    end
    endmodule
