use rand::prelude::*;
use rand::distributions::Uniform;

fn estimate_pi(n: u64) -> f64 {
    let dist = Uniform::new(0.0, 1.0);
    let mut rng = rand::thread_rng();
    let mut count_in = 0;
    let mut count_tot = 0;
    for _ in 0..n {
        let x = dist.sample(&mut rng);
        let y = dist.sample(&mut rng);
        let r_2 = x*x + y*y;
        if r_2 < 1. {
            count_in += 1;
        }
        count_tot += 1;
    }
    4. * (count_in as f64) / (count_tot as f64)
}

fn main() {
    let n = 100000000;
    println!("Estimate of Pi after {} trials is {}", n, estimate_pi(n));
}
