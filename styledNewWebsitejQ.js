function reset () {
	$("tr:odd").css('background-color', '#3EF9E5');
	$("tr:even").css('background-color', '#993EF9');
}

function change1() {
	$("tr:odd").css('background-color', '#f96d3e');
	$("tr:even").css('background-color', '#3e3ef9');
}

function change2() {
	$("#Option1,#Option2,#Option3,#Option4,#Option5,#Option6,#Option7,#Option8,#Option9").addClass('Color1');
}

function reset2 () {
	$("#Option1,#Option2,#Option3,#Option4,#Option5,#Option6,#Option7,#Option8,#Option9").removeClass('Color1');
}

function change3() {
	$("tr:odd").css('background-color', '#f9f93e');
	$("tr:even").css('background-color', '#f93eca');
}

function change4() {
	$("#Option4, #Option2, #Option6, #Option8").addClass('DiagonalC1a');
	$("#Option1, #Option3, #Option7, #Option9").addClass('DiagonalC1b');
	$("#Option5").addClass('DiagonalC1c');
}

function reset4() {
	$("#Option4, #Option2, #Option6, #Option8").removeClass('DiagonalC1a');
	$("#Option1, #Option3, #Option7, #Option9").removeClass('DiagonalC1b');
	$("#Option5").removeClass('DiagonalC1c');
}

function change5() {
	$("#Option1,#Option2,#Option3,#Option4,#Option5,#Option6,#Option7,#Option8,#Option9").addClass('Color2');
}

function reset5 () {
	$("#Option1,#Option2,#Option3,#Option4,#Option5,#Option6,#Option7,#Option8,#Option9").removeClass('Color2');
}

function change6() {
	$("#Option4, #Option2, #Option6, #Option8").addClass('DiagonalC2a');
	$("#Option1, #Option3, #Option7, #Option9").addClass('DiagonalC2b');
	$("#Option5").addClass('DiagonalC2c');
}

function reset6() {
	$("#Option4, #Option2, #Option6, #Option8").removeClass('DiagonalC2a');
	$("#Option1, #Option3, #Option7, #Option9").removeClass('DiagonalC2b');
	$("#Option5").removeClass('DiagonalC2c');
}

function change7() {
	$("tr:odd").css('background-color', '#00ff00');
	$("tr:even").css('background-color', '#990099');
}

function change8() {
	$("#Option1,#Option2,#Option3,#Option4,#Option5,#Option6,#Option7,#Option8,#Option9").addClass('Color3');
}

function reset8 () {
	$("#Option1,#Option2,#Option3,#Option4,#Option5,#Option6,#Option7,#Option8,#Option9").removeClass('Color3');
}

function change9() {
	$("tr:odd").css('background-color', '#663300');
	$("tr:even").css('background-color', '#ccccff');
}

$(document).ready(function() {
	
	$("#Option1").hover(function() {
		change1();
	},	
	
	function () {
		reset();
	});
	
	$("#Option2").hover(function() {
		change2();
	},
	
	function () {
		reset2();
	});
	
	$("#Option3").hover(function() {
		change3();
	},
	
	function () {
		reset();
	});
	
	$("#Option4").hover(function() {
		change4();
	},
	
	function () {
		reset4();
	});
	
	$("#Option5").hover(function() {
		change5();
	},
	
	function () {
		reset5();
	});
	
	$("#Option6").hover(function() {
		change6();
	},
	
	function () {
		reset6();
	});
	
	$("#Option7").hover(function() {
		change7();
	},
	
	function () {
		reset();
	});
	
	$("#Option8").hover(function() {
		change8();
	},
	
	function () {
		reset8();
	});
	
	$("#Option9").hover(function() {
		change9();
	},
	
	function () {
		reset();
	});
	
	
	
	var SlideC = $('.Slides').length;
	var SlideW = $('.Slides').width();
	var SlideH = $('.Slides').height();
	var Slider = SlideC * SlideW;
	
	$('.ImgSlider').css({ width:SlideW, height:SlideH });
	
	$('.Frames').css({ width:Slider, marginLeft: - SlideW });
	
	$('.Slides:last-child').prependTo('.Frames');
	
	function Left() {
        $('.Frames').animate({
            left: + SlideW
        }, 200, function () {
            $('.Slides:last-child').prependTo('.Frames');
            $('.Frames').css('left', '');
        });
    };

    function Right() {
        $('.Frames').animate({
            left: - SlideW
        }, 200, function () {
            $('.Slides:first-child').appendTo('.Frames');
            $('.Frames').css('left', '');
        });
    };
	
	$('.Prev').click(function () {
        Left();
    });

    $('.Next').click(function () {
        Right();
    });
	
	
	// creating a small circular progress loader
	var ctx = document.getElementById('circle').getContext('2d');
	var loaded = 0;
	var starting = 4.72;
	var can_w = ctx.canvas.width;
	var can_h = ctx.canvas.height;
	var difference;
	function progressSim () {
		difference = ((loaded/100)* Math.PI*2*10).toFixed(2);
		ctx.clearRect(0,0,can_w,can_h);
		ctx.lineWidth = 10;
		ctx.textAlign = 'center';
		ctx.strokeStyle= "black";
		ctx.fillStyle = "black";
		ctx.fillText(loaded+'%', can_w*.5, can_h*.5+2, can_w);
		ctx.beginPath();
		ctx.arc(35, 35, 30, starting, difference/10+starting, false);
		ctx.stroke();
		if (loaded >= 100){
			clearTimeout(simulate);
		}
		loaded++;
	}
	
	var simulate = setInterval(progressSim, 25);
	
	$('#Reset').click(function() {
		loaded = 0;
		simulate = setInterval(progressSim, 25);
	});
	
	// Code for the password tester, had to remove all classes each time
	 // to ensure if multiple characters are removed, valid password strength shown
	$('#PasswordTest').keyup(function(){
		var length = $('#PasswordTest').val().length;
		var checkpoints = 0;
		
		// add to checkpoints according to length of string
		if (length > 0) {
			if (length < 4)
				checkpoints += 1;
			else if (length < 8)
				checkpoints += 2;
			else if (length < 12)
				checkpoints += 3;
			else
				checkpoints += 4;
		}
		var passwordText = document.getElementById("PasswordTest");
		var Text = passwordText.value;
		var Chars = "!@#$%^&*_~`?><-+";
		var Numbers = "0123456789";
		
		// for every special char present, add 2 to checkpoints
		for (var i = 0; i < Text.length; i++) {
			if (Chars.indexOf(Text.charAt(i)) >= 0) {
				checkpoints += 2;
				$('#Strengths ul li:last-child').css('color', 'green');
			} else 
				$('#Strengths ul li:last-child').css('color', 'red');
			//changing text colors depending on whether criteria has been fullfilled
		}
		
		// Two separate for-loops because this one terminates as soon as 1 number is seen
		for (var j = 0; j < Text.length; j++){
			if (Numbers.indexOf(Text.charAt(j)) >= 0) {
				checkpoints += 2;
				$('#Strengths ul li:nth-child(3)').css('color', 'green');
				break;
			} else 
				$('#Strengths ul li:nth-child(3)').css('color', 'red');
				
		}
		
		if (/[a-z]/.test(Text)) {
			checkpoints++;
			$('#Strengths ul li:first-child').css('color', 'green');
		} else 
			$('#Strengths ul li:first-child').css('color', 'red');
		
		if (/[A-Z]/.test(Text)) {
			checkpoints += 2;
			$('#Strengths ul li:nth-child(2)').css('color', 'green');
		} else 
			$('#Strengths ul li:nth-child(2)').css('color', 'red');
		//changing text colors depending on whether criteria has been fullfilled

		
		//have to remove all complementary classes for each if statement 
		//to ensure proper check shown if multiple characters added/removed
		if (checkpoints == 0) {
			$('#Tester').removeClass('Weak');
			$('#Tester').removeClass('Good');
			$('#Tester').removeClass('VeryGood');
			$('#Tester').removeClass('Strong');
			$('#Tester').text('');
			$('#Strengths ul li').css('color', 'red');
		} else if (checkpoints < 3) {
			$('#Tester').removeClass('Good');
			$('#Tester').removeClass('VeryGood');
			$('#Tester').removeClass('Strong');
			$('#Tester').text('Weak');
			$('#Tester').addClass('Weak');
		} else if (checkpoints < 6) {
			$('#Tester').removeClass('Weak');
			$('#Tester').removeClass('VeryGood');
			$('#Tester').removeClass('Strong');
			$('#Tester').text('Good');
			$('#Tester').addClass('Good')
		} else if (checkpoints < 9) {
			$('#Tester').removeClass('Weak');
			$('#Tester').removeClass('Good');
			$('#Tester').removeClass('Strong');
			$('#Tester').text('Very Good');
			$('#Tester').addClass('VeryGood')
		} else {
			$('#Tester').removeClass('Weak');
			$('#Tester').removeClass('Good');
			$('#Tester').removeClass('VeryGood');
			$('#Tester').text('Strong');
			$('#Tester').addClass('Strong');
		}
		
		
	})
	
});
