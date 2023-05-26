package pl.edu.pg.eti.ksg.po.lab1.transformacje;
public class Punkt3D extends Punkt{
    private final double z;
    public Punkt3D(double x, double y, double z) {
        super(x,y);
        this.z = z;
    }
    public double getZ() {
        return z;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Punkt3D)
        {
            Punkt3D other = (Punkt3D)obj;
            return (this.getX() == other.getX() && this.getY() ==other.getY() && z == other.z);
        }
        return false;
    }
    @Override
    public int hashCode() {
        return 2081 * Double.hashCode(this.getX()) * Double.hashCode(this.getY()) * Double.hashCode(z) + 373;
    }
    @Override
    public String toString() {
        return "Instancja klasy Punkt3D zawierająca współrzędne x: " + this.getX() + " y: " + this.getY() + " z: " + z;
    }
}