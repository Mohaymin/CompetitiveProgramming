public class MyCircle {
    private MyPoint center;
    private int radius;
    
    MyPoint c = new MyPoint();
    
    public MyCircle(int x, int y, int radius)
    {
        MyPoint c1 = new MyPoint(x,y);
        this.radius= radius;
                
                
        
    }
    public MyCircle(MyPoint c, int r)
    {
        center= c;
        radius=r;
        
    }
    
    public int getRadius()
    {
        return radius;
    }
    
    public int setRadius(int radius)
    {
        this.radius=radius;
        return radius;
    }
    
    public MyPoint getCenter()
    {
        return center;
    }
    
    public MyPoint setCenter(MyPoint center)
    {
        this.center=center;
        return center;
    }
    
    public int getCenterX()
    {
        return c.getX();
    }
    
    public int getCenterY()
    {
        return c.getY();
    }
    
    public int setCenterXY(int x,int y)
    {
        x= c.getX();
        y=c.getY();
        return x ;
        //return y;
                
    }
    
    public String toString()
    {
        return "circle @" +c.toString()+" " +radius; 
    }
    
    public double getArea()
    {
        return 3.14*radius*radius;
    }
    
    
    
    
    
    
    
    
}
