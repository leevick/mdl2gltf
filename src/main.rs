use std::env;
use std::fs::File;
use std::io::Read;

mod blender {}
mod fsx {}

mod riff {
    struct Section {
        name: String,
        offset: usize,
        length: usize,
    }
}

const RIFF_TAG: [&str; 35] = [
    "RIFF", "MDLH", "MDLG", "MDLN", "SMAP", "PARA", "CRAS", "BBOX", "RADI", "MDLD", "TEXT", "MATE",
    "INDE", "VERB", "VERT", "TANS", "BMAP", "SKIN", "TRAN", "AMAP", "SCEN", "SGAL", "SGVL", "SGJC",
    "SGBR", "LODT", "LODE", "PART", "ANIB", "PLAL", "PLAT", "REFL", "REFP", "ATTO", "SHAM",
];

fn main() {
    // let args: Vec<String> = env::args().collect();
    // let file = File::open(&args[1]);
    let file = File::open("data/Il-86.MDL");
    let mut buffer = vec![0u8; 0x800000];
    let len = file.unwrap().read(&mut buffer).unwrap();
    println!("{}", len);

    for t in RIFF_TAG {
        println!("{}", t);
    }
}
