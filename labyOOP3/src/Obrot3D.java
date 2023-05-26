package pl.edu.pg.eti.ksg.po.lab1.transformacje;
import pl.edu.pg.eti.ksg.po.lab1.transformacje.ObrotOS;
import static java.lang.Math.*;
public class Obrot3D extends ObrotOS implements Transformacja3D{
    private final double beta, gamma;

    public Obrot3D(double alpha, double beta, double gamma) {
        super('x', alpha);
        this.beta = beta;
        this.gamma = gamma;
    }

    public Punkt3D transformuj(Punkt3D p) throws
            BrakTransformacjiOdwrotnejException {
        ObrotOS o1 = new ObrotOS('x', this.getAlpha());
        Punkt3D p1 = o1.transformuj3D(p);
        ObrotOS o2 = new ObrotOS('y', beta);
        Punkt3D p2 = o2.transformuj3D(p1);
        ObrotOS o3 = new ObrotOS('z', gamma);
        Punkt3D p3 = o3.transformuj3D(p2);
        return p3;
    }

}
