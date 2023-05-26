package pl.edu.pg.eti.ksg.po.lab1.transformacje;
public class ZlozenieTransformacji3D implements Transformacja3D {
    public Transformacja3D[] tab;
    public ZlozenieTransformacji3D(int size) {
        tab = new Transformacja3D[size];
    }
    /*@Override
    public Transformacja3D getTransformacjaOdwrotna3D() throws BrakTransformacjiOdwrotnejException{
        ZlozenieTransformacji3D zt2 = new ZlozenieTransformacji3D(tab.length);
        for (int i=0; i<tab.length; i++) {
            zt2.tab[tab.length -1 -i]=this.tab[i].getTransformacjaOdwrotna3D();
        }
        return zt2;
    }*/
    @Override
    public Punkt3D transformuj3D(Punkt3D p) {
        for (int i=0; i<tab.length; i++)
        {
            p=tab[i].transformuj3D(p);
        }
        return p;
    }

}
