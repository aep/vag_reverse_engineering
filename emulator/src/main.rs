extern crate socketcan;

fn main() {
    println!("Hello, world!");
    let sock = socketcan::CANSocket::open("can0").unwrap();


    loop {
        let frame = sock.read_frame().unwrap();
        println!("{:#?}", frame);



        if frame.id() == 0x765 &&
           frame.data()[0] == 0x3 &&
           frame.data()[1] == 0x22 &&
           frame.data()[2] == 0x1D &&
           frame.data()[3] == 0xD0
        {
            println!("got request for soc");
            let frame = socketcan::CANFrame::new(
                0x7cf,
                &[0x04, 0x62, 0x1d, 0xd0, 0xb5, 0xaa, 0xaa, 0xaa],
                false,
                false
            ).unwrap();

            sock.write_frame(&frame).unwrap();
        }


        if frame.id() == 0x7E0 &&
           frame.data()[0] == 0x3 &&
           frame.data()[1] == 0x22 &&
           frame.data()[2] == 0xf1 &&
           frame.data()[3] == 0x90
        {
            println!("got request for vin");
            let frame = socketcan::CANFrame::new(
                0x7E8,
                &[0x10, 0x13, 0x62, 0xF1, 0x90, 0x5A, 0x5A, 0x5A],
                false,
                false
            ).unwrap();

            sock.write_frame(&frame).unwrap();
        }

        if frame.id() == 0x7E0 &&
            frame.data()[0] == 0x30
            {
                println!("got request for more data");

                let frame = socketcan::CANFrame::new(
                    0x7E8,
                    &[0x21, b'a', b'b', b'c', b'd', b'e', b'f', b'g'],
                    false,
                    false
                    ).unwrap();
                sock.write_frame(&frame).unwrap();
                sock.write_frame(&frame).unwrap();

            }
    }
}
