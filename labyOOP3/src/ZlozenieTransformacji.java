package pl.edu.pg.eti.ksg.po.lab1.transformacje;
public class ZlozenieTransformacji implements Transformacja {
    public Transformacja[] tab;
    public ZlozenieTransformacji(int size) {
        tab = new Transformacja[size];
    }
    @Override
    public Transformacja getTransformacjaOdwrotna() throws BrakTransformacjiOdwrotnejException{
       ZlozenieTransformacji zt2 = new ZlozenieTransformacji(tab.length);
        for (int i=0; i<tab.length; i++) {
            zt2.tab[tab.length -1 -i]=this.tab[i].getTransformacjaOdwrotna();
        }
        return zt2;
    }
    @Override
    public Punkt transformuj(Punkt p) {
        for (int i=0; i<tab.length; i++)
        {
            p=tab[i].transformuj(p);
        }
        return p;
    }

    /*@Override
    public String toString() {
        return "Obrót o kąt: " + alpha;
    }*/
}
