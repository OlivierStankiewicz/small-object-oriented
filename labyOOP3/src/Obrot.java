package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import static java.lang.Math.*;
public class Obrot implements Transformacja {
    private final double alpha;
    public Obrot(double alpha) {
        this.alpha = alpha;
    }
    @Override
    public Transformacja getTransformacjaOdwrotna() {
        return new Obrot(-alpha);
    }
    @Override
    public Punkt transformuj(Punkt p) {
        return new Punkt(p.getX()*cos(alpha) - p.getY()*sin(alpha), p.getX()*sin(alpha) + p.getY()*cos(alpha));
    }
    public double getAlpha() {
        return alpha;
    }

    @Override
    public String toString() {
        return "Obrót o kąt: " + alpha;
    }
}
