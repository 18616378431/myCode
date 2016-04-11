var load_state = {  
    preload: function() { 
        this.game.load.image('bg','assets/img/bg.png');
		this.game.load.image('bo','assets/img/back.png');
		this.game.load.image('menu','assets/img/menu.png');
		this.game.load.image('ready','assets/img/ready.png');
        this.game.load.image('bird', 'assets/img/bird.png');
        this.game.load.image('pipe', 'assets/img/pipe.png');  
        this.game.load.audio('jump', 'assets/wav/jumpblock.mp3');
		this.game.load.audio('dead','assets/wav/dead.wav');
		this.game.load.image('gameover','assets/img/gameover.png');
    },

    create: function() {
		
        // When all assets are loaded, go to the 'menu' state
        this.game.state.start('menu');
		
    }
};