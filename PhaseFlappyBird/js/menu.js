var menu_state={
	create: function(){
		
		var space_key = this.game.input.keyboard.addKey(Phaser.Keyboard.SPACEBAR);
		space_key.onDown.add(this.start,this);
        //触摸事件
        var t = this;
        this.game.input.touch.onTouchStart = function(){
            t.start();
            console.log("down");
        }

		var style = {font: "30px Arial",fill: "#FFFFFF"};
		var x = game.world.width/2,y = game.world.height/2;
		
		this.bg = this.game.add.sprite(0,0,'bg');
		this.bo = this.game.add.sprite(0,0,'bo');
		this.menu = this.game.add.sprite(0,0,'menu');
		this.bird = this.game.add.sprite(x-30,y-60,'bird');
		
		var text = this.game.add.text(x,y-118,"Press space to start!",style);
		text.anchor.setTo(0.5,0.5);
		  
	},
	start:function(){
		this.game.state.start('ready');
	}
};