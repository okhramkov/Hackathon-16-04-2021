/*!
 * arparallax.js v0.1 (https://rodzyk.github.io/arparallax.js/)
 * Copyright (c) 2017 Andriy Rodzyk
 * Licensed under MIT (https://github.com/rodzyk/arparallax.js/blob/master/LICENSE)
 */



window.addEventListener('scroll', checkScroll, false);
window.addEventListener('resize', checkScroll, false);
(function ($) {
    $.fn.arparallax = function (options) {

        let settings = $.extend({
            'blur': 'auto',     // none, both, up, down, auto
            'depth': 'direct',   // direct, reverse, none
            'speed': .32, // 0 - 1
            'scaleMultiplier': .05,
            'blurMultiplier': 1,
            'imageContainer': '.image'
        }, options);

        function parallax(block, value, isScrollDown){
            let depth = value/10000;
            let scaleX = 1 + Math.abs((value) * (settings.scaleMultiplier ));
            let scaleY = 1 + Math.abs((value) * (settings.scaleMultiplier ));
            let blurValue = 0;
            switch (settings.blur) {
                case 'none': blurValue = 0; break;
                case 'both': blurValue = Math.abs(value*settings.blurMultiplier); break;
                case 'up': blurValue = value*settings.blurMultiplier; break;
                case 'down': blurValue = -value*settings.blurMultiplier; break;
                case 'auto': {
                    block.css({
                        'filter': `blur(0)`
                    });
                    blurValue = (isScrollDown)?value*settings.blurMultiplier:-value*settings.blurMultiplier; 
                    break};
                default: blurValue = 0; break;
            }

            switch (settings.depth) {
                case 'none': depth = 0; break;
                case 'direct': depth = depth; break;
                case 'reverse': depth = -depth; break;            
                default: depth = depth; break;
            }

            let speed = value * (settings.speed * 100);
            block.css({
                'transform': `matrix3d(${scaleX},0,0.00,0,0.00,${scaleY},0.00,${depth},0,0,1,0,0,${speed},0,1)`
            });
            block.css({
                'filter': `blur(${blurValue}px)`
            });
        }

        return this.each(function () {
            let imageBox = $(this);
            let image = imageBox.find(settings.imageContainer);            
            let scrollTop = $(window).scrollTop();
            image.css({ 'position': 'absolute', 'top': 0, 'bottom': 0, 'left': 0, 'right': 0 });
            $(window).scroll(function() {        
                let top = $(window).scrollTop();
                let isScrollDown = (top>scrollTop);
                scrollTop=top;
                let imageOffsetTop = imageBox.offset().top ;
                let imageOffsetBottom = imageOffsetTop + imageBox.outerHeight();
                let heightBody = $(window).outerHeight();
                let deltaToBottom =   (heightBody - imageOffsetBottom) + top;
                let deltaToTop = top - imageOffsetTop;
                let k = .01; 
                deltaToTop = Math.round(deltaToTop) *k;
                deltaToBottom = Math.round(deltaToBottom) *k;
                let val;
                if(deltaToBottom > -10 && deltaToBottom <0){ val = deltaToBottom;	}	
                else if(deltaToBottom <= -10){ val = -10;}	
                else if(deltaToTop>0 && deltaToTop <= 10) {	val = deltaToTop;}
                else if(deltaToTop > 10) { val = 10; }
                else if(deltaToTop<=0 && deltaToBottom >=0){val = 0;}
                parallax(image, val, isScrollDown);
        
            }).scroll();
        })
    };
})(jQuery);