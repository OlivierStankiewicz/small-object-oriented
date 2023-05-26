package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.Obrot;
import static java.lang.Math.*;

public class ObrotOS extends Obrot implements Transformacja3D{
    private final char os;

    public ObrotOS(char os, double alpha) {
        super(alpha);
        this.os = os;
    }
    public double getOS() {
        return os;
    }

    public Punkt3D transformuj3D(Punkt3D p){
         double alpha = this.getAlpha();
        if (os == 'x')
            return new Punkt3D(p.getX(), p.getX()*cos(alpha) - p.getY()*sin(alpha), p.getX()*sin(alpha) + p.getY()*cos(alpha));

        else if (os == 'y')
            return new Punkt3D(p.getX()*cos(alpha) - p.getY()*sin(alpha), p.getY(), p.getX()*sin(alpha) + p.getY()*cos(alpha));
        else
            return new Punkt3D(p.getX()*cos(alpha) - p.getY()*sin(alpha), p.getX()*sin(alpha) + p.getY()*cos(alpha), p.getZ());
    }

    @Override
    public String toString() {
        return "Obrot o os: " + os;
    }
}