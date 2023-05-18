$( "#register" ).submit(function( event ) {
    event.preventDefault();
    
    var $form = $( this ),
        raw = $form.find( "input[name='raw']" ).val();
    
    $.ajax({
        type: "POST",
        url: "/license",
        data: JSON.stringify({raw: raw}),
        contentType: "application/json",
        dataType: "json",
        success: function(d){
            alert(d.flag);
        },
        error: function(d){
            $("p#error").text(d.responseJSON.error);
        },
    });
});
