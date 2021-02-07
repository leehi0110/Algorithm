function vowelsAndConsonants(s) {
    let vowel = [];
    let consonant = [];
    
    for(let i=0;i<s.length;i++) {
        const chr = s[i];
        
        if(chr === 'a' || chr === 'e' || chr === 'i' || chr === 'o' || chr === 'u') {
            vowel.push(chr);
        } else {
            consonant.push(chr);
        }
    }
    
    for(let i=0;i<vowel.length;i++) {
        console.log(vowel[i]);
    }
    
    for(let i=0;i<consonant.length;i++) {
        console.log(consonant[i]);
    }
}

