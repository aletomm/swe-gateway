package redroundrobin.gateway;


import com.github.snksoft.crc.CRC;
import kafka.utils.Json;
import org.apache.commons.lang3.ArrayUtils;
import org.jetbrains.annotations.NotNull;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketTimeoutException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Random;

import static org.apache.commons.lang3.ArrayUtils.toPrimitive;


public class Gateway {

    private InetAddress indirizzo;
    private int porta;
    private List<Dispositivo> dispositivi = new ArrayList<>();

    public Gateway(InetAddress indirizzo, int porta) {
        this.indirizzo = indirizzo;
        this.porta = porta;

    }

    public InetAddress getIndirizzo() {
        return indirizzo;
    }

    public int getPorta() {
        return porta;
    }

    public List<Dispositivo> getDispositivi() {
        return dispositivi;
    }

    /*
     * Metodo che restituisce i dati prodotti da un dispositivo*/
    String riceviDati(InetAddress indirizzo, int porta) {
        try {

            InetAddress hostname = InetAddress.getLocalHost();
            DatagramSocket socket = new DatagramSocket();
           // Traduttore convertitore = new Traduttore();

            while (true) {
                byte[] pacchettoGenerato = creaPacchettoCasuale();

                DatagramPacket richiesta = new DatagramPacket(pacchettoGenerato, pacchettoGenerato.length, InetAddress.getLocalHost(), 6969);
                socket.send(richiesta);
                System.out.print("> REQ: ");
                System.out.print("[ ");
                for (byte elemento : pacchettoGenerato) {
                    System.out.print(elemento + " ");
                }
                System.out.println("]");


                byte[] buffer = new byte[5];
                DatagramPacket response = new DatagramPacket(buffer, buffer.length);
                socket.setSoTimeout(1000);
                socket.receive(response);


                List<Byte> pacchettoRicevuto = Arrays.asList(ArrayUtils.toObject(buffer));
                if(checkPacket(pacchettoRicevuto)){
                    traduttore.aggiungiSensore(pacchettoRicevuto);    //Da controllare

                }

                if(){
                    traduttore.getJson();
                    Produttore.
                }

                System.out.print("< RES: ");
                for (int i = 0; i < buffer.length; ++i)
                    System.out.print(buffer[i] + " ");
                System.out.println();
                //Arrays.asList(buffer).stream().forEach(x -> System.out.println(x));
                Thread.sleep(1000);
            }

        } catch (SocketTimeoutException e) {
            System.out.println("Errore di tempo fuori: " + e.getMessage());
            e.printStackTrace();
        } catch (IOException e) {
            System.out.println("Errore cliente: " + e.getMessage());
            e.printStackTrace();
        } catch (InterruptedException e) {
            System.out.println("Errore cliente: " + e.getMessage());
            e.printStackTrace();

       return null;
        }

    // Controllo il checksum del pacchetto ricevuto a meno del checksum
    private boolean checkPacket(@NotNull List<Byte> packet) {
        // System.out.println(packet.size());
        return packet.get(4) == calculateChecksum(packet.subList(0, 4));
    }

    // Creazione di un pacchetto random
    public static byte[] creaPacchettoCasuale() {
        Random rand = new Random();
        byte disp = (byte) (1 + rand.nextInt(1));
        byte codiceOperazione = 0;
        byte sensore = 0;
        byte valore = (byte) (1 + rand.nextInt(2));

        List<Byte> pacchetto = new ArrayList<>();
        pacchetto.add(disp);
        pacchetto.add(codiceOperazione);
        pacchetto.add(sensore);
        pacchetto.add(valore);

        return new byte[]{
                disp, codiceOperazione, sensore, valore,
                calculateChecksum(pacchetto)
        };

    }
    /* Checksum CRC-8 Bluetooth */
    public static byte calculateChecksum(@NotNull List<Byte> packet){

        Byte[] bytes = packet.toArray(new Byte[packet.size()]);

        byte tmp = (byte) CRC.calculateCRC(
                new CRC.Parameters(8, 0xa7, 0x00, true, true, 0x00),
                toPrimitive(bytes));
        //System.out.println(tmp);
        return tmp;
    }

    public static void main(String args[]){

    }


}
